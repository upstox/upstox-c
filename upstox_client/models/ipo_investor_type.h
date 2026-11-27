/*
 * ipo_investor_type.h
 *
 * 
 */

#ifndef _ipo_investor_type_H_
#define _ipo_investor_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_investor_type_t ipo_investor_type_t;


// Enum CATEGORY for ipo_investor_type

typedef enum  { upstox_client_ipo_investor_type_CATEGORY_NULL = 0, upstox_client_ipo_investor_type_CATEGORY_IND, upstox_client_ipo_investor_type_CATEGORY_HNI } upstox_client_ipo_investor_type_CATEGORY_e;

char* ipo_investor_type_category_ToString(upstox_client_ipo_investor_type_CATEGORY_e category);

upstox_client_ipo_investor_type_CATEGORY_e ipo_investor_type_category_FromString(char* category);



typedef struct ipo_investor_type_t {
    upstox_client_ipo_investor_type_CATEGORY_e category; //enum
    char *description; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_investor_type_t;

ipo_investor_type_t *ipo_investor_type_create(
    upstox_client_ipo_investor_type_CATEGORY_e category,
    char *description
);

void ipo_investor_type_free(ipo_investor_type_t *ipo_investor_type);

ipo_investor_type_t *ipo_investor_type_parseFromJSON(cJSON *ipo_investor_typeJSON);

cJSON *ipo_investor_type_convertToJSON(ipo_investor_type_t *ipo_investor_type);

#endif /* _ipo_investor_type_H_ */

