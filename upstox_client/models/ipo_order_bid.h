/*
 * ipo_order_bid.h
 *
 * 
 */

#ifndef _ipo_order_bid_H_
#define _ipo_order_bid_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_order_bid_t ipo_order_bid_t;




typedef struct ipo_order_bid_t {
    int *quantity; //numeric
    double *price; //numeric
    double *amount; //numeric
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_order_bid_t;

ipo_order_bid_t *ipo_order_bid_create(
    int *quantity,
    double *price,
    double *amount,
    char *message
);

void ipo_order_bid_free(ipo_order_bid_t *ipo_order_bid);

ipo_order_bid_t *ipo_order_bid_parseFromJSON(cJSON *ipo_order_bidJSON);

cJSON *ipo_order_bid_convertToJSON(ipo_order_bid_t *ipo_order_bid);

#endif /* _ipo_order_bid_H_ */

