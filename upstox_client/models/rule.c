#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rule.h"



static rule_t *rule_create_internal(
    char *strategy,
    char *status,
    char *message,
    char *trigger_type,
    double *trigger_price,
    char *transaction_type,
    char *order_id,
    double *trailing_gap
    ) {
    rule_t *rule_local_var = malloc(sizeof(rule_t));
    if (!rule_local_var) {
        return NULL;
    }
    memset(rule_local_var, 0, sizeof(rule_t));
    rule_local_var->_library_owned = 1;
    rule_local_var->strategy = strategy;
    rule_local_var->status = status;
    rule_local_var->message = message;
    rule_local_var->trigger_type = trigger_type;
    rule_local_var->trigger_price = trigger_price;
    rule_local_var->transaction_type = transaction_type;
    rule_local_var->order_id = order_id;
    rule_local_var->trailing_gap = trailing_gap;
    return rule_local_var;
}

rule_t *rule_create(
    char *strategy,
    char *status,
    char *message,
    char *trigger_type,
    double *trigger_price,
    char *transaction_type,
    char *order_id,
    double *trailing_gap
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
    rule_t *result = rule_create_internal (
        strategy,
        status,
        message,
        trigger_type,
        trigger_price_copy,
        transaction_type,
        order_id,
        trailing_gap_copy
        );
    if (!result) {
        free(trigger_price_copy);
        free(trailing_gap_copy);
    }
    return result;
}

void rule_free(rule_t *rule) {
    if(NULL == rule){
        return ;
    }
    if(rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (rule->strategy) {
        free(rule->strategy);
        rule->strategy = NULL;
    }
    if (rule->status) {
        free(rule->status);
        rule->status = NULL;
    }
    if (rule->message) {
        free(rule->message);
        rule->message = NULL;
    }
    if (rule->trigger_type) {
        free(rule->trigger_type);
        rule->trigger_type = NULL;
    }
    if (rule->trigger_price) {
        free(rule->trigger_price);
        rule->trigger_price = NULL;
    }
    if (rule->transaction_type) {
        free(rule->transaction_type);
        rule->transaction_type = NULL;
    }
    if (rule->order_id) {
        free(rule->order_id);
        rule->order_id = NULL;
    }
    if (rule->trailing_gap) {
        free(rule->trailing_gap);
        rule->trailing_gap = NULL;
    }
    free(rule);
}

cJSON *rule_convertToJSON(rule_t *rule) {
    cJSON *item = cJSON_CreateObject();

    // rule->strategy
    if(rule->strategy) {
    if(cJSON_AddStringToObject(item, "strategy", rule->strategy) == NULL) {
    goto fail; //String
    }
    }


    // rule->status
    if(rule->status) {
    if(cJSON_AddStringToObject(item, "status", rule->status) == NULL) {
    goto fail; //String
    }
    }


    // rule->message
    if(rule->message) {
    if(cJSON_AddStringToObject(item, "message", rule->message) == NULL) {
    goto fail; //String
    }
    }


    // rule->trigger_type
    if(rule->trigger_type) {
    if(cJSON_AddStringToObject(item, "trigger_type", rule->trigger_type) == NULL) {
    goto fail; //String
    }
    }


    // rule->trigger_price
    if(rule->trigger_price) {
    if(cJSON_AddNumberToObject(item, "trigger_price", *rule->trigger_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // rule->transaction_type
    if(rule->transaction_type) {
    if(cJSON_AddStringToObject(item, "transaction_type", rule->transaction_type) == NULL) {
    goto fail; //String
    }
    }


    // rule->order_id
    if(rule->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", rule->order_id) == NULL) {
    goto fail; //String
    }
    }


    // rule->trailing_gap
    if(rule->trailing_gap) {
    if(cJSON_AddNumberToObject(item, "trailing_gap", *rule->trailing_gap) == NULL) {
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

rule_t *rule_parseFromJSON(cJSON *ruleJSON){

    rule_t *rule_local_var = NULL;

    char *strategy_local_str = NULL;

    char *status_local_str = NULL;

    char *message_local_str = NULL;

    char *trigger_type_local_str = NULL;

    // define the local variable for rule->trigger_price
    double *trigger_price_local_var = NULL;

    char *transaction_type_local_str = NULL;

    char *order_id_local_str = NULL;

    // define the local variable for rule->trailing_gap
    double *trailing_gap_local_var = NULL;

    // rule->strategy
    cJSON *strategy = cJSON_GetObjectItemCaseSensitive(ruleJSON, "strategy");
    if (cJSON_IsNull(strategy)) {
        strategy = NULL;
    }
    if (strategy) { 
    if(!cJSON_IsString(strategy) && !cJSON_IsNull(strategy))
    {
    goto end; //String
    }
    }

    // rule->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(ruleJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // rule->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(ruleJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // rule->trigger_type
    cJSON *trigger_type = cJSON_GetObjectItemCaseSensitive(ruleJSON, "trigger_type");
    if (cJSON_IsNull(trigger_type)) {
        trigger_type = NULL;
    }
    if (trigger_type) { 
    if(!cJSON_IsString(trigger_type) && !cJSON_IsNull(trigger_type))
    {
    goto end; //String
    }
    }

    // rule->trigger_price
    cJSON *trigger_price = cJSON_GetObjectItemCaseSensitive(ruleJSON, "trigger_price");
    if (cJSON_IsNull(trigger_price)) {
        trigger_price = NULL;
    }
    if (trigger_price) { 
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
    }

    // rule->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(ruleJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (transaction_type) { 
    if(!cJSON_IsString(transaction_type) && !cJSON_IsNull(transaction_type))
    {
    goto end; //String
    }
    }

    // rule->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(ruleJSON, "order_id");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (order_id) { 
    if(!cJSON_IsString(order_id) && !cJSON_IsNull(order_id))
    {
    goto end; //String
    }
    }

    // rule->trailing_gap
    cJSON *trailing_gap = cJSON_GetObjectItemCaseSensitive(ruleJSON, "trailing_gap");
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


    if (strategy && !cJSON_IsNull(strategy)) strategy_local_str = strdup(strategy->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (trigger_type && !cJSON_IsNull(trigger_type)) trigger_type_local_str = strdup(trigger_type->valuestring);
    if (transaction_type && !cJSON_IsNull(transaction_type)) transaction_type_local_str = strdup(transaction_type->valuestring);
    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);

    rule_local_var = rule_create_internal (
        strategy_local_str,
        status_local_str,
        message_local_str,
        trigger_type_local_str,
        trigger_price_local_var,
        transaction_type_local_str,
        order_id_local_str,
        trailing_gap_local_var
        );

    if (!rule_local_var) {
        goto end;
    }

    return rule_local_var;
end:
    if (strategy_local_str) {
        free(strategy_local_str);
        strategy_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (trigger_type_local_str) {
        free(trigger_type_local_str);
        trigger_type_local_str = NULL;
    }
    if (trigger_price_local_var) {
        free(trigger_price_local_var);
        trigger_price_local_var = NULL;
    }
    if (transaction_type_local_str) {
        free(transaction_type_local_str);
        transaction_type_local_str = NULL;
    }
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    if (trailing_gap_local_var) {
        free(trailing_gap_local_var);
        trailing_gap_local_var = NULL;
    }
    return NULL;

}
