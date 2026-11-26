/*
 * gtt_order_details.h
 *
 * 
 */

#ifndef _gtt_order_details_H_
#define _gtt_order_details_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gtt_order_details_t gtt_order_details_t;

#include "rule.h"



typedef struct gtt_order_details_t {
    char *type; // string
    char *exchange; // string
    int *quantity; //numeric
    char *product; // string
    list_t *rules; //nonprimitive container
    char *trading_symbol; // string
    char *instrument_token; // string
    char *gtt_order_id; // string
    long *expires_at; //numeric
    long *created_at; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} gtt_order_details_t;

gtt_order_details_t *gtt_order_details_create(
    char *type,
    char *exchange,
    int *quantity,
    char *product,
    list_t *rules,
    char *trading_symbol,
    char *instrument_token,
    char *gtt_order_id,
    long *expires_at,
    long *created_at
);

void gtt_order_details_free(gtt_order_details_t *gtt_order_details);

gtt_order_details_t *gtt_order_details_parseFromJSON(cJSON *gtt_order_detailsJSON);

cJSON *gtt_order_details_convertToJSON(gtt_order_details_t *gtt_order_details);

#endif /* _gtt_order_details_H_ */

