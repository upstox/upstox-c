/*
 * family_member_data.h
 *
 * 
 */

#ifndef _family_member_data_H_
#define _family_member_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct family_member_data_t family_member_data_t;




typedef struct family_member_data_t {
    char *user_id; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} family_member_data_t;

family_member_data_t *family_member_data_create(
    char *user_id,
    char *name
);

void family_member_data_free(family_member_data_t *family_member_data);

family_member_data_t *family_member_data_parseFromJSON(cJSON *family_member_dataJSON);

cJSON *family_member_data_convertToJSON(family_member_data_t *family_member_data);

#endif /* _family_member_data_H_ */

