/*
 * depth_map.h
 *
 * 
 */

#ifndef _depth_map_H_
#define _depth_map_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct depth_map_t depth_map_t;

#include "depth.h"



typedef struct depth_map_t {
    list_t *buy; //nonprimitive container
    list_t *sell; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} depth_map_t;

depth_map_t *depth_map_create(
    list_t *buy,
    list_t *sell
);

void depth_map_free(depth_map_t *depth_map);

depth_map_t *depth_map_parseFromJSON(cJSON *depth_mapJSON);

cJSON *depth_map_convertToJSON(depth_map_t *depth_map);

#endif /* _depth_map_H_ */

