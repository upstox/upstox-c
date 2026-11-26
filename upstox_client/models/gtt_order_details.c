#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gtt_order_details.h"



static gtt_order_details_t *gtt_order_details_create_internal(
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
    ) {
    gtt_order_details_t *gtt_order_details_local_var = malloc(sizeof(gtt_order_details_t));
    if (!gtt_order_details_local_var) {
        return NULL;
    }
    memset(gtt_order_details_local_var, 0, sizeof(gtt_order_details_t));
    gtt_order_details_local_var->_library_owned = 1;
    gtt_order_details_local_var->type = type;
    gtt_order_details_local_var->exchange = exchange;
    gtt_order_details_local_var->quantity = quantity;
    gtt_order_details_local_var->product = product;
    gtt_order_details_local_var->rules = rules;
    gtt_order_details_local_var->trading_symbol = trading_symbol;
    gtt_order_details_local_var->instrument_token = instrument_token;
    gtt_order_details_local_var->gtt_order_id = gtt_order_id;
    gtt_order_details_local_var->expires_at = expires_at;
    gtt_order_details_local_var->created_at = created_at;
    return gtt_order_details_local_var;
}

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
    ) {
    int *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(int));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    long *expires_at_copy = NULL;
    if (expires_at) {
        expires_at_copy = malloc(sizeof(long));
        if (expires_at_copy) *expires_at_copy = *expires_at;
    }
    long *created_at_copy = NULL;
    if (created_at) {
        created_at_copy = malloc(sizeof(long));
        if (created_at_copy) *created_at_copy = *created_at;
    }
    gtt_order_details_t *result = gtt_order_details_create_internal (
        type,
        exchange,
        quantity_copy,
        product,
        rules,
        trading_symbol,
        instrument_token,
        gtt_order_id,
        expires_at_copy,
        created_at_copy
        );
    if (!result) {
        free(quantity_copy);
        free(expires_at_copy);
        free(created_at_copy);
    }
    return result;
}

void gtt_order_details_free(gtt_order_details_t *gtt_order_details) {
    if(NULL == gtt_order_details){
        return ;
    }
    if(gtt_order_details->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gtt_order_details_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gtt_order_details->type) {
        free(gtt_order_details->type);
        gtt_order_details->type = NULL;
    }
    if (gtt_order_details->exchange) {
        free(gtt_order_details->exchange);
        gtt_order_details->exchange = NULL;
    }
    if (gtt_order_details->quantity) {
        free(gtt_order_details->quantity);
        gtt_order_details->quantity = NULL;
    }
    if (gtt_order_details->product) {
        free(gtt_order_details->product);
        gtt_order_details->product = NULL;
    }
    if (gtt_order_details->rules) {
        list_ForEach(listEntry, gtt_order_details->rules) {
            rule_free(listEntry->data);
        }
        list_freeList(gtt_order_details->rules);
        gtt_order_details->rules = NULL;
    }
    if (gtt_order_details->trading_symbol) {
        free(gtt_order_details->trading_symbol);
        gtt_order_details->trading_symbol = NULL;
    }
    if (gtt_order_details->instrument_token) {
        free(gtt_order_details->instrument_token);
        gtt_order_details->instrument_token = NULL;
    }
    if (gtt_order_details->gtt_order_id) {
        free(gtt_order_details->gtt_order_id);
        gtt_order_details->gtt_order_id = NULL;
    }
    if (gtt_order_details->expires_at) {
        free(gtt_order_details->expires_at);
        gtt_order_details->expires_at = NULL;
    }
    if (gtt_order_details->created_at) {
        free(gtt_order_details->created_at);
        gtt_order_details->created_at = NULL;
    }
    free(gtt_order_details);
}

cJSON *gtt_order_details_convertToJSON(gtt_order_details_t *gtt_order_details) {
    cJSON *item = cJSON_CreateObject();

    // gtt_order_details->type
    if(gtt_order_details->type) {
    if(cJSON_AddStringToObject(item, "type", gtt_order_details->type) == NULL) {
    goto fail; //String
    }
    }


    // gtt_order_details->exchange
    if(gtt_order_details->exchange) {
    if(cJSON_AddStringToObject(item, "exchange", gtt_order_details->exchange) == NULL) {
    goto fail; //String
    }
    }


    // gtt_order_details->quantity
    if(gtt_order_details->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *gtt_order_details->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // gtt_order_details->product
    if(gtt_order_details->product) {
    if(cJSON_AddStringToObject(item, "product", gtt_order_details->product) == NULL) {
    goto fail; //String
    }
    }


    // gtt_order_details->rules
    if(gtt_order_details->rules) {
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (gtt_order_details->rules) {
    list_ForEach(rulesListEntry, gtt_order_details->rules) {
    cJSON *itemLocal = rule_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
    }
    }
    }


    // gtt_order_details->trading_symbol
    if(gtt_order_details->trading_symbol) {
    if(cJSON_AddStringToObject(item, "trading_symbol", gtt_order_details->trading_symbol) == NULL) {
    goto fail; //String
    }
    }


    // gtt_order_details->instrument_token
    if(gtt_order_details->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", gtt_order_details->instrument_token) == NULL) {
    goto fail; //String
    }
    }


    // gtt_order_details->gtt_order_id
    if(gtt_order_details->gtt_order_id) {
    if(cJSON_AddStringToObject(item, "gtt_order_id", gtt_order_details->gtt_order_id) == NULL) {
    goto fail; //String
    }
    }


    // gtt_order_details->expires_at
    if(gtt_order_details->expires_at) {
    if(cJSON_AddNumberToObject(item, "expires_at", *gtt_order_details->expires_at) == NULL) {
    goto fail; //Numeric
    }
    }


    // gtt_order_details->created_at
    if(gtt_order_details->created_at) {
    if(cJSON_AddNumberToObject(item, "created_at", *gtt_order_details->created_at) == NULL) {
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

gtt_order_details_t *gtt_order_details_parseFromJSON(cJSON *gtt_order_detailsJSON){

    gtt_order_details_t *gtt_order_details_local_var = NULL;

    char *type_local_str = NULL;

    char *exchange_local_str = NULL;

    // define the local variable for gtt_order_details->quantity
    int *quantity_local_var = NULL;

    char *product_local_str = NULL;

    // define the local list for gtt_order_details->rules
    list_t *rulesList = NULL;

    char *trading_symbol_local_str = NULL;

    char *instrument_token_local_str = NULL;

    char *gtt_order_id_local_str = NULL;

    // define the local variable for gtt_order_details->expires_at
    long *expires_at_local_var = NULL;

    // define the local variable for gtt_order_details->created_at
    long *created_at_local_var = NULL;

    // gtt_order_details->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(gtt_order_detailsJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // gtt_order_details->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(gtt_order_detailsJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    if (exchange) { 
    if(!cJSON_IsString(exchange) && !cJSON_IsNull(exchange))
    {
    goto end; //String
    }
    }

    // gtt_order_details->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(gtt_order_detailsJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (quantity) { 
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }
    quantity_local_var = malloc(sizeof(int));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;
    }

    // gtt_order_details->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(gtt_order_detailsJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    if (product) { 
    if(!cJSON_IsString(product) && !cJSON_IsNull(product))
    {
    goto end; //String
    }
    }

    // gtt_order_details->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(gtt_order_detailsJSON, "rules");
    if (cJSON_IsNull(rules)) {
        rules = NULL;
    }
    if (rules) { 
    cJSON *rules_local_nonprimitive = NULL;
    if(!cJSON_IsArray(rules)){
        goto end; //nonprimitive container
    }

    rulesList = list_createList();

    cJSON_ArrayForEach(rules_local_nonprimitive,rules )
    {
        if(!cJSON_IsObject(rules_local_nonprimitive)){
            goto end;
        }
        rule_t *rulesItem = rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }
    }

    // gtt_order_details->trading_symbol
    cJSON *trading_symbol = cJSON_GetObjectItemCaseSensitive(gtt_order_detailsJSON, "trading_symbol");
    if (cJSON_IsNull(trading_symbol)) {
        trading_symbol = NULL;
    }
    if (trading_symbol) { 
    if(!cJSON_IsString(trading_symbol) && !cJSON_IsNull(trading_symbol))
    {
    goto end; //String
    }
    }

    // gtt_order_details->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(gtt_order_detailsJSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }

    // gtt_order_details->gtt_order_id
    cJSON *gtt_order_id = cJSON_GetObjectItemCaseSensitive(gtt_order_detailsJSON, "gtt_order_id");
    if (cJSON_IsNull(gtt_order_id)) {
        gtt_order_id = NULL;
    }
    if (gtt_order_id) { 
    if(!cJSON_IsString(gtt_order_id) && !cJSON_IsNull(gtt_order_id))
    {
    goto end; //String
    }
    }

    // gtt_order_details->expires_at
    cJSON *expires_at = cJSON_GetObjectItemCaseSensitive(gtt_order_detailsJSON, "expires_at");
    if (cJSON_IsNull(expires_at)) {
        expires_at = NULL;
    }
    if (expires_at) { 
    if(!cJSON_IsNumber(expires_at))
    {
    goto end; //Numeric
    }
    expires_at_local_var = malloc(sizeof(long));
    if(!expires_at_local_var)
    {
        goto end;
    }
    *expires_at_local_var = expires_at->valuedouble;
    }

    // gtt_order_details->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(gtt_order_detailsJSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsNumber(created_at))
    {
    goto end; //Numeric
    }
    created_at_local_var = malloc(sizeof(long));
    if(!created_at_local_var)
    {
        goto end;
    }
    *created_at_local_var = created_at->valuedouble;
    }


    if (type && !cJSON_IsNull(type)) type_local_str = strdup(type->valuestring);
    if (exchange && !cJSON_IsNull(exchange)) exchange_local_str = strdup(exchange->valuestring);
    if (product && !cJSON_IsNull(product)) product_local_str = strdup(product->valuestring);
    if (trading_symbol && !cJSON_IsNull(trading_symbol)) trading_symbol_local_str = strdup(trading_symbol->valuestring);
    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);
    if (gtt_order_id && !cJSON_IsNull(gtt_order_id)) gtt_order_id_local_str = strdup(gtt_order_id->valuestring);

    gtt_order_details_local_var = gtt_order_details_create_internal (
        type_local_str,
        exchange_local_str,
        quantity_local_var,
        product_local_str,
        rules ? rulesList : NULL,
        trading_symbol_local_str,
        instrument_token_local_str,
        gtt_order_id_local_str,
        expires_at_local_var,
        created_at_local_var
        );

    if (!gtt_order_details_local_var) {
        goto end;
    }

    return gtt_order_details_local_var;
end:
    if (type_local_str) {
        free(type_local_str);
        type_local_str = NULL;
    }
    if (exchange_local_str) {
        free(exchange_local_str);
        exchange_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (product_local_str) {
        free(product_local_str);
        product_local_str = NULL;
    }
    if (rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rulesList) {
            rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rulesList);
        rulesList = NULL;
    }
    if (trading_symbol_local_str) {
        free(trading_symbol_local_str);
        trading_symbol_local_str = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    if (gtt_order_id_local_str) {
        free(gtt_order_id_local_str);
        gtt_order_id_local_str = NULL;
    }
    if (expires_at_local_var) {
        free(expires_at_local_var);
        expires_at_local_var = NULL;
    }
    if (created_at_local_var) {
        free(created_at_local_var);
        created_at_local_var = NULL;
    }
    return NULL;

}
