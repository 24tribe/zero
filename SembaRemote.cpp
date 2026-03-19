#include "SembaRemote.h"

#include <curl/curl.h>

#include <cstdlib>
#include <string>
#include <vector>

struct SembaRemote {
    std::string url;
};

extern "C" SembaRemote *SembaRemote_Init(const char *url, SembaStatus *status) {
    SembaRemote *remote;

    try {
        remote = new SembaRemote();
    } catch (std::bad_alloc&) {
        if (status) { *status = SEMBA_STATUS_ALLOC_ERROR; }
        return NULL;
    }

    remote->url = url;

    if (status) { *status = SEMBA_STATUS_OK; }

    return remote;
}

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    (void)size;

    auto& data = *reinterpret_cast<std::vector<char>*>(userdata);

    size_t old_size = data.size();

    data.resize(old_size + nmemb);

    ::memcpy(&(data[old_size]), ptr, nmemb);

    return nmemb;
}

char *copy_string(std::string s) {
    char *result = new char[s.size() + 1];
    ::memcpy(result, &(s[0]), s.size() + 1);
    return result;
}

extern "C" char *SembaRemote_Call(
    SembaRemote *ctx, const char *path, const char *req, SembaStatus *status
) {
    if (!ctx) {
        if (status) { *status = SEMBA_STATUS_INVALID_CONTEXT; }
        return NULL;
    }

    CURL *curl = curl_easy_init();

    if (!curl) {
        if (status) { *status = SEMBA_STATUS_ALLOC_ERROR; }
        return NULL;
    }

    std::string url = ctx->url + std::string(path);

    std::vector<char> data;

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charset: utf-8");

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, req);

    char *result;

    if (curl_easy_perform(curl)) {
        if (status) { *status = SEMBA_STATUS_EXCEPTION; }
        result = copy_string("curl_easy_perform failed!");
    } else {
        result = copy_string(std::string(data.begin(), data.end()));
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        if (status) {
            if (http_code == 200) {
                *status = SEMBA_STATUS_OK;
            } else {
                *status = SEMBA_STATUS_EXCEPTION;
            }
        }
    }

    curl_easy_cleanup(curl);

    return result;
}

extern "C" void SembaRemote_FreeResponse(char *response) {
    delete[] response;
}

extern "C" void SembaRemote_Deinit(SembaRemote *ctx) {
    delete ctx;
}