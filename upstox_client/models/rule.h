/*
 * rule.h
 *
 * 
 */

#ifndef _rule_H_
#define _rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct rule_t rule_t;




typedef struct rule_t {
    char *strategy; // string
    char *status; // string
    char *message; // string
    char *trigger_type; // string
    double *trigger_price; //numeric
    char *transaction_type; // string
    char *order_id; // string
    double *trailing_gap; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} rule_t;

rule_t *rule_create(
    char *strategy,
    char *status,
    char *message,
    char *trigger_type,
    double *trigger_price,
    char *transaction_type,
    char *order_id,
    double *trailing_gap
);

void rule_free(rule_t *rule);

rule_t *rule_parseFromJSON(cJSON *ruleJSON);

cJSON *rule_convertToJSON(rule_t *rule);

#endif /* _rule_H_ */

