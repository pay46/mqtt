#ifndef MOSQUITTO_BROKER_H
#define MOSQUITTO_BROKER_H
#include "mosquitto_internal.h"
#include "config.h"
#include "uthash.h"

typedef uint64_t dbid_t;

struct _mosquitto_subhier {
    struct _mosquitto_subhier *parent;
    struct _mosquitto_subhier *children;
    struct _mosquitto_subhier *next;
    struct _mosquitto_subleaf *subs;
    char *topic;
    struct mosquitto_msg_store *retained;
};

struct _mosquitto_unpwd {
    char *username;
    char *password;
#ifdef WITH_TLS
    unsigned int password_len;
    unsigned int salt_len;
    unsigned char *salt;
#endif
    UT_hash_handle hh;
};

struct mosquitto_db {
    dbid_t last_db_id;
    struct _mosquitto_subhier subs;
    struct _mosquitto_unpwd *unpwd;
};
#endif /* MOSQUITTO_BROKER_H */

