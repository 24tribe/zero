#include "GachaRatesWindow.h"

#include <jansson.h>
#include <imgui.h>

#include <cmath>

GachaRatesWindow::GachaRatesWindow() : getGachaRates(),
                                       setGachaRates(),
                                       initialized(false),
                                       error(""),
                                       getGachaRatesError(""),
                                       getGachaRatesThread(nullptr)
{
}

bool GachaRatesWindow::InitGachaRates() {
    json_t* gachaRates = getGachaRates();

    if (!gachaRates) {
        getGachaRatesError = "getGachaRates returned null!!";
        return false;
    }

    json_t* normalPullThreeStarCharRate = json_object_get(gachaRates, "NormalPullThreeStarCharRateId");

    if (!normalPullThreeStarCharRate) {
        getGachaRatesError = "normalPullThreeStarCharRate is missing from response!!!";
        return false;
    }

    json_t* normalPullThreeStarTCRate = json_object_get(gachaRates, "NormalPullThreeStarTCRateId");

    if (!normalPullThreeStarTCRate) {
        getGachaRatesError = "normalPullThreeStarTCRate is missing from response!!!";
        return false;
    }

    json_t* normalPullTwoStarCharRate = json_object_get(gachaRates, "NormalPullTwoStarCharRateId");

    if (!normalPullTwoStarCharRate) {
        getGachaRatesError = "normalPullTwoStarCharRate is missing from response!!!";
        return false;
    }

    json_t* normalPullTwoStarTCRate = json_object_get(gachaRates, "NormalPullTwoStarTCRateId");

    if (!normalPullTwoStarTCRate) {
        getGachaRatesError = "normalPullTwoStarTCRate is missing from response!!!";
        return false;
    }

    json_t* normalPullOneStarTCRate = json_object_get(gachaRates, "NormalPullOneStarTCRateId");

    if (!normalPullOneStarTCRate) {
        getGachaRatesError = "normalPullOneStarTCRate is missing from response!!!";
        return false;
    }

    json_t* guaranteedPullThreeStarCharRate = json_object_get(gachaRates, "GuaranteedPullThreeStarCharRateId");

    if (!guaranteedPullThreeStarCharRate) {
        getGachaRatesError = "guaranteedPullThreeStarCharRate is missing from response!!!";
        return false;
    }

    json_t* guaranteedPullThreeStarTCRate = json_object_get(gachaRates, "GuaranteedPullThreeStarTCRateId");

    if (!guaranteedPullThreeStarTCRate) {
        getGachaRatesError = "guaranteedPullThreeStarTCRate is missing from response!!!";
        return false;
    }

    json_t* promisedPullThreeStarCharRate = json_object_get(gachaRates, "PromisedPullThreeStarCharRateId");

    if (!promisedPullThreeStarCharRate) {
        getGachaRatesError = "promisedPullThreeStarCharRate is missing from response!!!";
        return false;
    }

    json_t* promisedPullThreeStarTCRate = json_object_get(gachaRates, "PromisedPullThreeStarTCRateId");

    if (!promisedPullThreeStarTCRate) {
        getGachaRatesError = "promisedPullThreeStarTCRate is missing from response!!!";
        return false;
    }

    json_t* promisedPullTwoStarCharRate = json_object_get(gachaRates, "PromisedPullTwoStarCharRateId");

    if (!promisedPullTwoStarCharRate) {
        getGachaRatesError = "promisedPullTwoStarCharRate is missing from response!!!";
        return false;
    }

    json_t* promisedPullTwoStarTCRate = json_object_get(gachaRates, "PromisedPullTwoStarTCRateId");

    if (!promisedPullTwoStarTCRate) {
        getGachaRatesError = "promisedPullTwoStarTCRate is missing from response!!!";
        return false;
    }

    normalPullRates.threeStarCharRate = json_real_value(normalPullThreeStarCharRate);
    normalPullRates.threeStarTCRate = json_real_value(normalPullThreeStarTCRate);
    normalPullRates.twoStarCharRate = json_real_value(normalPullTwoStarCharRate);
    normalPullRates.twoStarTCRate = json_real_value(normalPullTwoStarTCRate);
    normalPullRates.oneStarTCRate = json_real_value(normalPullOneStarTCRate);

    guaranteedPullRates.threeStarCharRate = json_real_value(guaranteedPullThreeStarCharRate);
    guaranteedPullRates.threeStarTCRate = json_real_value(guaranteedPullThreeStarTCRate);

    promisedPullRates.threeStarCharRate = json_real_value(promisedPullThreeStarCharRate);
    promisedPullRates.threeStarTCRate = json_real_value(promisedPullThreeStarTCRate);
    promisedPullRates.twoStarCharRate = json_real_value(promisedPullTwoStarCharRate);
    promisedPullRates.twoStarTCRate = json_real_value(promisedPullTwoStarTCRate);

    json_decref(gachaRates);

    return true;
}

void GachaRatesWindow::ApplyGachaRates() {
    json_t* req = json_object();

    json_object_set_new(req, "NormalPullThreeStarCharRateId", json_real(normalPullRates.threeStarCharRate));
    json_object_set_new(req, "NormalPullThreeStarTCRateId", json_real(normalPullRates.threeStarTCRate));
    json_object_set_new(req, "NormalPullTwoStarCharRateId", json_real(normalPullRates.twoStarCharRate));
    json_object_set_new(req, "NormalPullTwoStarTCRateId", json_real(normalPullRates.twoStarTCRate));
    json_object_set_new(req, "NormalPullOneStarTCRateId", json_real(normalPullRates.oneStarTCRate));

    json_object_set_new(req, "GuaranteedPullThreeStarCharRateId", json_real(guaranteedPullRates.threeStarCharRate));
    json_object_set_new(req, "GuaranteedPullThreeStarTCRateId", json_real(guaranteedPullRates.threeStarTCRate));

    json_object_set_new(req, "PromisedPullThreeStarCharRateId", json_real(promisedPullRates.threeStarCharRate));
    json_object_set_new(req, "PromisedPullThreeStarTCRateId", json_real(promisedPullRates.threeStarTCRate));
    json_object_set_new(req, "PromisedPullTwoStarCharRateId", json_real(promisedPullRates.twoStarCharRate));
    json_object_set_new(req, "PromisedPullTwoStarTCRateId", json_real(promisedPullRates.twoStarTCRate));

    setGachaRates(req);
    json_decref(req);

    setGachaRatesResult = "Applied gacha rates!";
}

int initGachaRates(void *gachaRatesWindowPtr) {
    auto& gachaRatesWindow = *reinterpret_cast<GachaRatesWindow*>(gachaRatesWindowPtr);

    gachaRatesWindow.InitGachaRates();

    return 0;
}

int setGachaRatesStart(void *gachaRatesWindowPtr) {
    auto& gachaRatesWindow = *reinterpret_cast<GachaRatesWindow*>(gachaRatesWindowPtr);

    gachaRatesWindow.ApplyGachaRates();

    return 0;
}

void ensureHundredPercent(
    float* changed,
    float* threeStarCharRate, float* threeStarTCRate,
    float* twoStarCharRate, float* twoStarTCRate, float* oneStarTCRate
) {
    if (*changed > 100.0) {
        *changed = fmod(*changed, 100.0);
    }

    float sum = (threeStarCharRate ? *threeStarCharRate : 0.0)
        + (threeStarTCRate ? *threeStarTCRate : 0.0)
        + (twoStarCharRate ? *twoStarCharRate : 0.0)
        + (twoStarTCRate ? *twoStarTCRate : 0.0)
        + (oneStarTCRate ? *oneStarTCRate : 0.0);

    if (sum != 100.0) {
        float delta = 100.0 - sum;
        float nonChangedSum = (threeStarCharRate && (threeStarCharRate != changed) ? *threeStarCharRate : 0.0)
            + (threeStarTCRate && (threeStarTCRate != changed) ? *threeStarTCRate : 0.0)
            + (twoStarCharRate && (twoStarCharRate != changed) ? *twoStarCharRate : 0.0)
            + (twoStarTCRate && (twoStarTCRate != changed) ? *twoStarTCRate : 0.0)
            + (oneStarTCRate && (oneStarTCRate != changed) ? *oneStarTCRate : 0.0);

        if (nonChangedSum != 0.0) {
            if (threeStarCharRate && changed != threeStarCharRate) {
                *threeStarCharRate += (delta * *threeStarCharRate)/nonChangedSum;
            }

            if (threeStarTCRate && changed != threeStarTCRate) {
                *threeStarTCRate += (delta * *threeStarTCRate)/nonChangedSum;
            }

            if (twoStarCharRate && changed != twoStarCharRate) {
                *twoStarCharRate += (delta * *twoStarCharRate)/nonChangedSum;
            }

            if (twoStarTCRate && changed != twoStarTCRate) {
                *twoStarTCRate += (delta * *twoStarTCRate)/nonChangedSum;
            }

            if (oneStarTCRate && changed != oneStarTCRate) {
                *oneStarTCRate += (delta * *oneStarTCRate)/nonChangedSum;
            }
        } else {
            if (threeStarCharRate && changed != threeStarCharRate) {
                *threeStarCharRate += delta;
            } else if (threeStarTCRate && changed != threeStarTCRate) {
                *threeStarTCRate += delta;
            } else if (twoStarCharRate && changed != twoStarCharRate) {
                *twoStarCharRate += delta;
            } else if (twoStarTCRate && changed != twoStarTCRate) {
                *twoStarTCRate += delta;
            } else if (oneStarTCRate && changed != oneStarTCRate) {
                *oneStarTCRate += delta;
            }
        }
    }
}

void GachaRatesWindow::Show(bool* showGachaRates) {
    ImGui::SetNextWindowSize(ImVec2(400,400), ImGuiCond_FirstUseEver);

    if (!ImGui::Begin("GachaRates", showGachaRates)) {
        ImGui::End();
        return;
    }

    if (error != "") {
        ImGui::Text("Error: %s", error.c_str());
    } else if (initialized) {
        if (result != "") {
            ImGui::Text("Result: %s", result.c_str());
        }

        if (setGachaRatesThread) {
            switch (WaitForSingleObject(setGachaRatesThread, 0)) {
            case WAIT_TIMEOUT:
                /* do nothing */
                break;
            case WAIT_OBJECT_0:
                result = setGachaRatesResult;
                CloseHandle(setGachaRatesThread);
                setGachaRatesThread = nullptr;
                break;
            default:
                error = "WaitForSingleObject failed!!";
                break;
            }
        }

        if (ImGui::Button("Apply gacha rates")) {
            if (setGachaRates) {
                setGachaRatesThread = CreateThread(
                    NULL, 0, (LPTHREAD_START_ROUTINE)setGachaRatesStart, this, 0, NULL
                );

                if (!setGachaRatesThread) {
                    result = "Failed to create setGachaRates thread";
                }
            } else {
                result = "setGachaRates func ptr is missing!";
            }
        }

        ImGui::SeparatorText("Normal pull");
        if (ImGui::DragFloat("threeStarCharRate", &normalPullRates.threeStarCharRate, 1.0f, 0.0f, 100.0f)) {
            ensureHundredPercent(
                &normalPullRates.threeStarCharRate,
                &normalPullRates.threeStarCharRate,
                &normalPullRates.threeStarTCRate,
                &normalPullRates.twoStarCharRate,
                &normalPullRates.twoStarTCRate,
                &normalPullRates.oneStarTCRate
            );
        }
        if (ImGui::DragFloat("threeStarTCRate", &normalPullRates.threeStarTCRate, 1.0f, 0.0f, 100.0f)) {
            ensureHundredPercent(
                &normalPullRates.threeStarTCRate,
                &normalPullRates.threeStarCharRate,
                &normalPullRates.threeStarTCRate,
                &normalPullRates.twoStarCharRate,
                &normalPullRates.twoStarTCRate,
                &normalPullRates.oneStarTCRate
            );
        }
        if (ImGui::DragFloat("twoStarCharRate", &normalPullRates.twoStarCharRate, 1.0f, 0.0f, 100.0f)) {
            ensureHundredPercent(
                &normalPullRates.twoStarCharRate,
                &normalPullRates.threeStarCharRate,
                &normalPullRates.threeStarTCRate,
                &normalPullRates.twoStarCharRate,
                &normalPullRates.twoStarTCRate,
                &normalPullRates.oneStarTCRate
            );
        }
        if (ImGui::DragFloat("twoStarTCRate", &normalPullRates.twoStarTCRate, 1.0f, 0.0f, 100.0f)) {
            ensureHundredPercent(
                &normalPullRates.twoStarTCRate,
                &normalPullRates.threeStarCharRate,
                &normalPullRates.threeStarTCRate,
                &normalPullRates.twoStarCharRate,
                &normalPullRates.twoStarTCRate,
                &normalPullRates.oneStarTCRate
            );
        }
        if (ImGui::DragFloat("oneStarTCRate", &normalPullRates.oneStarTCRate, 1.0f, 0.0f, 100.0f)) {
            ensureHundredPercent(
                &normalPullRates.oneStarTCRate,
                &normalPullRates.threeStarCharRate,
                &normalPullRates.threeStarTCRate,
                &normalPullRates.twoStarCharRate,
                &normalPullRates.twoStarTCRate,
                &normalPullRates.oneStarTCRate
            );
        }

        ImGui::SeparatorText("Promised pull (every 10 pulls)");
        if (ImGui::DragFloat("threeStarCharRate##1", &promisedPullRates.threeStarCharRate, 1.0f, 0.0f, 100.0f)) {
            ensureHundredPercent(
                &promisedPullRates.threeStarCharRate,
                &promisedPullRates.threeStarCharRate,
                &promisedPullRates.threeStarTCRate,
                &promisedPullRates.twoStarCharRate,
                &promisedPullRates.twoStarTCRate,
                nullptr
            );
        }
        if (ImGui::DragFloat("threeStarTCRate##1", &promisedPullRates.threeStarTCRate, 1.0f, 0.0f, 100.0f)) {
            ensureHundredPercent(
                &promisedPullRates.threeStarTCRate,
                &promisedPullRates.threeStarCharRate,
                &promisedPullRates.threeStarTCRate,
                &promisedPullRates.twoStarCharRate,
                &promisedPullRates.twoStarTCRate,
                nullptr
            );
        }
        if (ImGui::DragFloat("twoStarCharRate##1", &promisedPullRates.twoStarCharRate, 1.0f, 0.0f, 100.0f)) {
            ensureHundredPercent(
                &promisedPullRates.twoStarCharRate,
                &promisedPullRates.threeStarCharRate,
                &promisedPullRates.threeStarTCRate,
                &promisedPullRates.twoStarCharRate,
                &promisedPullRates.twoStarTCRate,
                nullptr
            );
        }
        if (ImGui::DragFloat("twoStarTCRate##1", &promisedPullRates.twoStarTCRate, 1.0f, 0.0f, 100.0f)) {
            ensureHundredPercent(
                &promisedPullRates.twoStarTCRate,
                &promisedPullRates.threeStarCharRate,
                &promisedPullRates.threeStarTCRate,
                &promisedPullRates.twoStarCharRate,
                &promisedPullRates.twoStarTCRate,
                nullptr
            );
        }

        ImGui::SeparatorText("Guaranteed pull (every 80 pulls)");
        if (ImGui::DragFloat("threeStarCharRate##2", &guaranteedPullRates.threeStarCharRate, 1.0f, 0.0f, 100.0f)) {
            ensureHundredPercent(
                &guaranteedPullRates.threeStarCharRate,
                &guaranteedPullRates.threeStarCharRate,
                &guaranteedPullRates.threeStarTCRate,
                nullptr,
                nullptr,
                nullptr
            );
        }
        if (ImGui::DragFloat("threeStarTCRate##2", &guaranteedPullRates.threeStarTCRate, 1.0f, 0.0f, 100.0f)) {
            ensureHundredPercent(
                &guaranteedPullRates.threeStarTCRate,
                &guaranteedPullRates.threeStarCharRate,
                &guaranteedPullRates.threeStarTCRate,
                nullptr,
                nullptr,
                nullptr
            );
        }
    } else {
        if (getGachaRates) {
            if (getGachaRatesThread) {
                switch (WaitForSingleObject(getGachaRatesThread, 0)) {
                case WAIT_TIMEOUT:
                    /* do nothing */
                    break;
                case WAIT_OBJECT_0:
                    if (getGachaRatesError != "") {
                        error = getGachaRatesError;
                    } else {
                        initialized = true;
                    }
                    CloseHandle(getGachaRatesThread);
                    getGachaRatesThread = nullptr;
                    break;
                default:
                    error = "WaitForSingleObject failed!!";
                    break;
                }
            } else {
                getGachaRatesThread = CreateThread(
                    NULL, 0, (LPTHREAD_START_ROUTINE)initGachaRates, this, 0, NULL
                );

                if (!getGachaRatesThread) {
                    error = "Failed to create getGachaRates thread!!";
                }
            }

            ImGui::Text("Initializing window...");
        } else {
            ImGui::Text("getGachaRates not set!!!");
        }
    }

    ImGui::End();
}