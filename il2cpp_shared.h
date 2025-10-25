#ifndef IL2CPP_SHARED_H_7_SEP_2025_10_40
#define IL2CPP_SHARED_H_7_SEP_2025_10_40

typedef struct Il2CppDomain Il2CppDomain;
typedef struct System_String_o System_String_o;
typedef struct Il2CppClass Il2CppClass;

typedef struct Il2CppObject
{
    Il2CppClass *klass;
    void *monitor;
} Il2CppObject;

typedef Il2CppDomain *(*IL2CPPDOMAINGET)(void);
extern IL2CPPDOMAINGET il2cpp_domain_get;

typedef void (*IL2CPPTHREADATTACH)(Il2CppDomain *);
extern IL2CPPTHREADATTACH il2cpp_thread_attach;

typedef Il2CppObject *(*IL2CPPOBJECTNEW)(const Il2CppClass *klass);
extern IL2CPPOBJECTNEW il2cpp_object_new;

typedef System_String_o *(*IL2CPPSTRINGNEW)(char *s);
extern IL2CPPSTRINGNEW il2cpp_string_new;

#endif