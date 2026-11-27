/*
 * problem.h
 *
 * 
 */

#ifndef _problem_H_
#define _problem_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct problem_t problem_t;

#include "object.h"



typedef struct problem_t {
    char *message; // string
    char *error_code; // string
    char *property_path; // string
    object_t *invalid_value; //object

    int _library_owned; // Is the library responsible for freeing this object?
} problem_t;

problem_t *problem_create(
    char *message,
    char *error_code,
    char *property_path,
    object_t *invalid_value
);

void problem_free(problem_t *problem);

problem_t *problem_parseFromJSON(cJSON *problemJSON);

cJSON *problem_convertToJSON(problem_t *problem);

#endif /* _problem_H_ */

