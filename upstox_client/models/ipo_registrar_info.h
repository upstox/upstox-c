/*
 * ipo_registrar_info.h
 *
 * 
 */

#ifndef _ipo_registrar_info_H_
#define _ipo_registrar_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_registrar_info_t ipo_registrar_info_t;




typedef struct ipo_registrar_info_t {
    char *name; // string
    char *email; // string
    char *contact_name; // string
    char *contact_number; // string
    char *website; // string
    char *registrar; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_registrar_info_t;

ipo_registrar_info_t *ipo_registrar_info_create(
    char *name,
    char *email,
    char *contact_name,
    char *contact_number,
    char *website,
    char *registrar
);

void ipo_registrar_info_free(ipo_registrar_info_t *ipo_registrar_info);

ipo_registrar_info_t *ipo_registrar_info_parseFromJSON(cJSON *ipo_registrar_infoJSON);

cJSON *ipo_registrar_info_convertToJSON(ipo_registrar_info_t *ipo_registrar_info);

#endif /* _ipo_registrar_info_H_ */

