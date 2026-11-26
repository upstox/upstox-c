/*
 * gtt_rule.h
 *
 * 
 */

#ifndef _gtt_rule_H_
#define _gtt_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gtt_rule_t gtt_rule_t;


// Enum STRATEGY for gtt_rule

typedef enum  { upstox_client_gtt_rule_STRATEGY_NULL = 0, upstox_client_gtt_rule_STRATEGY_ENTRY, upstox_client_gtt_rule_STRATEGY_STOPLOSS, upstox_client_gtt_rule_STRATEGY_TARGET } upstox_client_gtt_rule_STRATEGY_e;

char* gtt_rule_strategy_ToString(upstox_client_gtt_rule_STRATEGY_e strategy);

upstox_client_gtt_rule_STRATEGY_e gtt_rule_strategy_FromString(char* strategy);

// Enum TRIGGERTYPE for gtt_rule

typedef enum  { upstox_client_gtt_rule_TRIGGERTYPE_NULL = 0, upstox_client_gtt_rule_TRIGGERTYPE_ABOVE, upstox_client_gtt_rule_TRIGGERTYPE_BELOW, upstox_client_gtt_rule_TRIGGERTYPE_IMMEDIATE } upstox_client_gtt_rule_TRIGGERTYPE_e;

char* gtt_rule_trigger_type_ToString(upstox_client_gtt_rule_TRIGGERTYPE_e trigger_type);

upstox_client_gtt_rule_TRIGGERTYPE_e gtt_rule_trigger_type_FromString(char* trigger_type);



typedef struct gtt_rule_t {
    upstox_client_gtt_rule_STRATEGY_e strategy; //enum
    upstox_client_gtt_rule_TRIGGERTYPE_e trigger_type; //enum
    double *trigger_price; //numeric
    double *trailing_gap; //numeric
    double *market_protection; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} gtt_rule_t;

gtt_rule_t *gtt_rule_create(
    upstox_client_gtt_rule_STRATEGY_e strategy,
    upstox_client_gtt_rule_TRIGGERTYPE_e trigger_type,
    double *trigger_price,
    double *trailing_gap,
    double *market_protection
);

void gtt_rule_free(gtt_rule_t *gtt_rule);

gtt_rule_t *gtt_rule_parseFromJSON(cJSON *gtt_ruleJSON);

cJSON *gtt_rule_convertToJSON(gtt_rule_t *gtt_rule);

#endif /* _gtt_rule_H_ */

