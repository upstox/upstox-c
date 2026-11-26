#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gtt_rule.h"


char* gtt_rule_strategy_ToString(upstox_client_gtt_rule_STRATEGY_e strategy) {
    char* strategyArray[] =  { "NULL", "ENTRY", "STOPLOSS", "TARGET" };
    return strategyArray[strategy];
}

upstox_client_gtt_rule_STRATEGY_e gtt_rule_strategy_FromString(char* strategy){
    int stringToReturn = 0;
    char *strategyArray[] =  { "NULL", "ENTRY", "STOPLOSS", "TARGET" };
    size_t sizeofArray = sizeof(strategyArray) / sizeof(strategyArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(strategy, strategyArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* gtt_rule_trigger_type_ToString(upstox_client_gtt_rule_TRIGGERTYPE_e trigger_type) {
    char* trigger_typeArray[] =  { "NULL", "ABOVE", "BELOW", "IMMEDIATE" };
    return trigger_typeArray[trigger_type];
}

upstox_client_gtt_rule_TRIGGERTYPE_e gtt_rule_trigger_type_FromString(char* trigger_type){
    int stringToReturn = 0;
    char *trigger_typeArray[] =  { "NULL", "ABOVE", "BELOW", "IMMEDIATE" };
    size_t sizeofArray = sizeof(trigger_typeArray) / sizeof(trigger_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(trigger_type, trigger_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static gtt_rule_t *gtt_rule_create_internal(
    upstox_client_gtt_rule_STRATEGY_e strategy,
    upstox_client_gtt_rule_TRIGGERTYPE_e trigger_type,
    double *trigger_price,
    double *trailing_gap,
    double *market_protection
    ) {
    gtt_rule_t *gtt_rule_local_var = malloc(sizeof(gtt_rule_t));
    if (!gtt_rule_local_var) {
        return NULL;
    }
    memset(gtt_rule_local_var, 0, sizeof(gtt_rule_t));
    gtt_rule_local_var->_library_owned = 1;
    gtt_rule_local_var->strategy = strategy;
    gtt_rule_local_var->trigger_type = trigger_type;
    gtt_rule_local_var->trigger_price = trigger_price;
    gtt_rule_local_var->trailing_gap = trailing_gap;
    gtt_rule_local_var->market_protection = market_protection;
    return gtt_rule_local_var;
}

gtt_rule_t *gtt_rule_create(
    upstox_client_gtt_rule_STRATEGY_e strategy,
    upstox_client_gtt_rule_TRIGGERTYPE_e trigger_type,
    double *trigger_price,
    double *trailing_gap,
    double *market_protection
    ) {
    double *trigger_price_copy = NULL;
    if (trigger_price) {
        trigger_price_copy = malloc(sizeof(double));
        if (trigger_price_copy) *trigger_price_copy = *trigger_price;
    }
    double *trailing_gap_copy = NULL;
    if (trailing_gap) {
        trailing_gap_copy = malloc(sizeof(double));
        if (trailing_gap_copy) *trailing_gap_copy = *trailing_gap;
    }
    double *market_protection_copy = NULL;
    if (market_protection) {
        market_protection_copy = malloc(sizeof(double));
        if (market_protection_copy) *market_protection_copy = *market_protection;
    }
    gtt_rule_t *result = gtt_rule_create_internal (
        strategy,
        trigger_type,
        trigger_price_copy,
        trailing_gap_copy,
        market_protection_copy
        );
    if (!result) {
        free(trigger_price_copy);
        free(trailing_gap_copy);
        free(market_protection_copy);
    }
    return result;
}

void gtt_rule_free(gtt_rule_t *gtt_rule) {
    if(NULL == gtt_rule){
        return ;
    }
    if(gtt_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gtt_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gtt_rule->trigger_price) {
        free(gtt_rule->trigger_price);
        gtt_rule->trigger_price = NULL;
    }
    if (gtt_rule->trailing_gap) {
        free(gtt_rule->trailing_gap);
        gtt_rule->trailing_gap = NULL;
    }
    if (gtt_rule->market_protection) {
        free(gtt_rule->market_protection);
        gtt_rule->market_protection = NULL;
    }
    free(gtt_rule);
}

cJSON *gtt_rule_convertToJSON(gtt_rule_t *gtt_rule) {
    cJSON *item = cJSON_CreateObject();

    // gtt_rule->strategy
    if (upstox_client_gtt_rule_STRATEGY_NULL == gtt_rule->strategy) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "strategy", gtt_rule_strategy_ToString(gtt_rule->strategy)) == NULL)
    {
    goto fail; //Enum
    }


    // gtt_rule->trigger_type
    if (upstox_client_gtt_rule_TRIGGERTYPE_NULL == gtt_rule->trigger_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "trigger_type", gtt_rule_trigger_type_ToString(gtt_rule->trigger_type)) == NULL)
    {
    goto fail; //Enum
    }


    // gtt_rule->trigger_price
    if (!gtt_rule->trigger_price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "trigger_price", *gtt_rule->trigger_price) == NULL) {
    goto fail; //Numeric
    }


    // gtt_rule->trailing_gap
    if(gtt_rule->trailing_gap) {
    if(cJSON_AddNumberToObject(item, "trailing_gap", *gtt_rule->trailing_gap) == NULL) {
    goto fail; //Numeric
    }
    }


    // gtt_rule->market_protection
    if(gtt_rule->market_protection) {
    if(cJSON_AddNumberToObject(item, "market_protection", *gtt_rule->market_protection) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gtt_rule_t *gtt_rule_parseFromJSON(cJSON *gtt_ruleJSON){

    gtt_rule_t *gtt_rule_local_var = NULL;

    // define the local variable for gtt_rule->trigger_price
    double *trigger_price_local_var = NULL;

    // define the local variable for gtt_rule->trailing_gap
    double *trailing_gap_local_var = NULL;

    // define the local variable for gtt_rule->market_protection
    double *market_protection_local_var = NULL;

    // gtt_rule->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(gtt_ruleJSON, "strategy");
    if (cJSON_IsNull(strategy)) {
        strategy = NULL;
    }
    if (!strategy) {
        goto end;
    }

    upstox_client_gtt_rule_STRATEGY_e strategyVariable;
    
    if(!cJSON_IsString(strategy))
    {
    goto end; //Enum
    }
    strategyVariable = gtt_rule_strategy_FromString(strategy->valuestring);

    // gtt_rule->trigger_type
    cJSON *trigger_type = cJSON_GetObjectItemCaseSensitive(gtt_ruleJSON, "trigger_type");
    if (cJSON_IsNull(trigger_type)) {
        trigger_type = NULL;
    }
    if (!trigger_type) {
        goto end;
    }

    upstox_client_gtt_rule_TRIGGERTYPE_e trigger_typeVariable;
    
    if(!cJSON_IsString(trigger_type))
    {
    goto end; //Enum
    }
    trigger_typeVariable = gtt_rule_trigger_type_FromString(trigger_type->valuestring);

    // gtt_rule->trigger_price
    cJSON *trigger_price = cJSON_GetObjectItemCaseSensitive(gtt_ruleJSON, "trigger_price");
    if (cJSON_IsNull(trigger_price)) {
        trigger_price = NULL;
    }
    if (!trigger_price) {
        goto end;
    }

    
    if(!cJSON_IsNumber(trigger_price))
    {
    goto end; //Numeric
    }
    trigger_price_local_var = malloc(sizeof(double));
    if(!trigger_price_local_var)
    {
        goto end;
    }
    *trigger_price_local_var = trigger_price->valuedouble;

    // gtt_rule->trailing_gap
    cJSON *trailing_gap = cJSON_GetObjectItemCaseSensitive(gtt_ruleJSON, "trailing_gap");
    if (cJSON_IsNull(trailing_gap)) {
        trailing_gap = NULL;
    }
    if (trailing_gap) { 
    if(!cJSON_IsNumber(trailing_gap))
    {
    goto end; //Numeric
    }
    trailing_gap_local_var = malloc(sizeof(double));
    if(!trailing_gap_local_var)
    {
        goto end;
    }
    *trailing_gap_local_var = trailing_gap->valuedouble;
    }

    // gtt_rule->market_protection
    cJSON *market_protection = cJSON_GetObjectItemCaseSensitive(gtt_ruleJSON, "market_protection");
    if (cJSON_IsNull(market_protection)) {
        market_protection = NULL;
    }
    if (market_protection) { 
    if(!cJSON_IsNumber(market_protection))
    {
    goto end; //Numeric
    }
    market_protection_local_var = malloc(sizeof(double));
    if(!market_protection_local_var)
    {
        goto end;
    }
    *market_protection_local_var = market_protection->valuedouble;
    }



    gtt_rule_local_var = gtt_rule_create_internal (
        strategyVariable,
        trigger_typeVariable,
        trigger_price_local_var,
        trailing_gap_local_var,
        market_protection_local_var
        );

    if (!gtt_rule_local_var) {
        goto end;
    }

    return gtt_rule_local_var;
end:
    if (trigger_price_local_var) {
        free(trigger_price_local_var);
        trigger_price_local_var = NULL;
    }
    if (trailing_gap_local_var) {
        free(trailing_gap_local_var);
        trailing_gap_local_var = NULL;
    }
    if (market_protection_local_var) {
        free(market_protection_local_var);
        market_protection_local_var = NULL;
    }
    return NULL;

}
