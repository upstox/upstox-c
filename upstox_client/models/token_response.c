#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "token_response.h"


char* token_response_exchanges_ToString(upstox_client_token_response_EXCHANGES_e exchanges) {
    char *exchangesArray[] =  { "NULL", "NSE", "NFO", "CDS", "BSE", "BFO", "BCD", "MCX", "NSCOM", "NSE_EG" };
    return exchangesArray[exchanges - 1];
}

upstox_client_token_response_EXCHANGES_e token_response_exchanges_FromString(char* exchanges) {
    int stringToReturn = 0;
    char *exchangesArray[] =  { "NULL", "NSE", "NFO", "CDS", "BSE", "BFO", "BCD", "MCX", "NSCOM", "NSE_EG" };
    size_t sizeofArray = sizeof(exchangesArray) / sizeof(exchangesArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(exchanges, exchangesArray[stringToReturn]) == 0) {
            return stringToReturn + 1;
        }
        stringToReturn++;
    }
    return 0;
}
char* token_response_products_ToString(upstox_client_token_response_PRODUCTS_e products) {
    char *productsArray[] =  { "NULL", "I", "D", "CO", "OCO", "MTF" };
    return productsArray[products - 1];
}

upstox_client_token_response_PRODUCTS_e token_response_products_FromString(char* products) {
    int stringToReturn = 0;
    char *productsArray[] =  { "NULL", "I", "D", "CO", "OCO", "MTF" };
    size_t sizeofArray = sizeof(productsArray) / sizeof(productsArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(products, productsArray[stringToReturn]) == 0) {
            return stringToReturn + 1;
        }
        stringToReturn++;
    }
    return 0;
}
char* token_response_order_types_ToString(upstox_client_token_response_ORDERTYPES_e order_types) {
    char *order_typesArray[] =  { "NULL", "MARKET", "LIMIT", "SL", "SL-M" };
    return order_typesArray[order_types - 1];
}

upstox_client_token_response_ORDERTYPES_e token_response_order_types_FromString(char* order_types) {
    int stringToReturn = 0;
    char *order_typesArray[] =  { "NULL", "MARKET", "LIMIT", "SL", "SL-M" };
    size_t sizeofArray = sizeof(order_typesArray) / sizeof(order_typesArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(order_types, order_typesArray[stringToReturn]) == 0) {
            return stringToReturn + 1;
        }
        stringToReturn++;
    }
    return 0;
}

static token_response_t *token_response_create_internal(
    char *email,
    list_t *exchanges,
    list_t *products,
    char *broker,
    char *user_id,
    char *user_name,
    list_t *order_types,
    char *user_type,
    int *poa,
    int *ddpi,
    int *is_active,
    char *access_token,
    char *extended_token,
    int *expires_in,
    char *token_type,
    char *refresh_token,
    int *refresh_token_expires_in
    ) {
    token_response_t *token_response_local_var = malloc(sizeof(token_response_t));
    if (!token_response_local_var) {
        return NULL;
    }
    memset(token_response_local_var, 0, sizeof(token_response_t));
    token_response_local_var->_library_owned = 1;
    token_response_local_var->email = email;
    token_response_local_var->exchanges = exchanges;
    token_response_local_var->products = products;
    token_response_local_var->broker = broker;
    token_response_local_var->user_id = user_id;
    token_response_local_var->user_name = user_name;
    token_response_local_var->order_types = order_types;
    token_response_local_var->user_type = user_type;
    token_response_local_var->poa = poa;
    token_response_local_var->ddpi = ddpi;
    token_response_local_var->is_active = is_active;
    token_response_local_var->access_token = access_token;
    token_response_local_var->extended_token = extended_token;
    token_response_local_var->expires_in = expires_in;
    token_response_local_var->token_type = token_type;
    token_response_local_var->refresh_token = refresh_token;
    token_response_local_var->refresh_token_expires_in = refresh_token_expires_in;
    return token_response_local_var;
}

token_response_t *token_response_create(
    char *email,
    list_t *exchanges,
    list_t *products,
    char *broker,
    char *user_id,
    char *user_name,
    list_t *order_types,
    char *user_type,
    int *poa,
    int *ddpi,
    int *is_active,
    char *access_token,
    char *extended_token,
    int *expires_in,
    char *token_type,
    char *refresh_token,
    int *refresh_token_expires_in
    ) {
    int *poa_copy = NULL;
    if (poa) {
        poa_copy = malloc(sizeof(int));
        if (poa_copy) *poa_copy = *poa;
    }
    int *ddpi_copy = NULL;
    if (ddpi) {
        ddpi_copy = malloc(sizeof(int));
        if (ddpi_copy) *ddpi_copy = *ddpi;
    }
    int *is_active_copy = NULL;
    if (is_active) {
        is_active_copy = malloc(sizeof(int));
        if (is_active_copy) *is_active_copy = *is_active;
    }
    int *expires_in_copy = NULL;
    if (expires_in) {
        expires_in_copy = malloc(sizeof(int));
        if (expires_in_copy) *expires_in_copy = *expires_in;
    }
    int *refresh_token_expires_in_copy = NULL;
    if (refresh_token_expires_in) {
        refresh_token_expires_in_copy = malloc(sizeof(int));
        if (refresh_token_expires_in_copy) *refresh_token_expires_in_copy = *refresh_token_expires_in;
    }
    token_response_t *result = token_response_create_internal (
        email,
        exchanges,
        products,
        broker,
        user_id,
        user_name,
        order_types,
        user_type,
        poa_copy,
        ddpi_copy,
        is_active_copy,
        access_token,
        extended_token,
        expires_in_copy,
        token_type,
        refresh_token,
        refresh_token_expires_in_copy
        );
    if (!result) {
        free(poa_copy);
        free(ddpi_copy);
        free(is_active_copy);
        free(expires_in_copy);
        free(refresh_token_expires_in_copy);
    }
    return result;
}

void token_response_free(token_response_t *token_response) {
    if(NULL == token_response){
        return ;
    }
    if(token_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "token_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (token_response->email) {
        free(token_response->email);
        token_response->email = NULL;
    }
    if (token_response->exchanges) {
        list_ForEach(listEntry, token_response->exchanges) {
            free(listEntry->data);
        }
        list_freeList(token_response->exchanges);
        token_response->exchanges = NULL;
    }
    if (token_response->products) {
        list_ForEach(listEntry, token_response->products) {
            free(listEntry->data);
        }
        list_freeList(token_response->products);
        token_response->products = NULL;
    }
    if (token_response->broker) {
        free(token_response->broker);
        token_response->broker = NULL;
    }
    if (token_response->user_id) {
        free(token_response->user_id);
        token_response->user_id = NULL;
    }
    if (token_response->user_name) {
        free(token_response->user_name);
        token_response->user_name = NULL;
    }
    if (token_response->order_types) {
        list_ForEach(listEntry, token_response->order_types) {
            free(listEntry->data);
        }
        list_freeList(token_response->order_types);
        token_response->order_types = NULL;
    }
    if (token_response->user_type) {
        free(token_response->user_type);
        token_response->user_type = NULL;
    }
    if (token_response->poa) {
        free(token_response->poa);
        token_response->poa = NULL;
    }
    if (token_response->ddpi) {
        free(token_response->ddpi);
        token_response->ddpi = NULL;
    }
    if (token_response->is_active) {
        free(token_response->is_active);
        token_response->is_active = NULL;
    }
    if (token_response->access_token) {
        free(token_response->access_token);
        token_response->access_token = NULL;
    }
    if (token_response->extended_token) {
        free(token_response->extended_token);
        token_response->extended_token = NULL;
    }
    if (token_response->expires_in) {
        free(token_response->expires_in);
        token_response->expires_in = NULL;
    }
    if (token_response->token_type) {
        free(token_response->token_type);
        token_response->token_type = NULL;
    }
    if (token_response->refresh_token) {
        free(token_response->refresh_token);
        token_response->refresh_token = NULL;
    }
    if (token_response->refresh_token_expires_in) {
        free(token_response->refresh_token_expires_in);
        token_response->refresh_token_expires_in = NULL;
    }
    free(token_response);
}

cJSON *token_response_convertToJSON(token_response_t *token_response) {
    cJSON *item = cJSON_CreateObject();

    // token_response->email
    if(token_response->email) {
    if(cJSON_AddStringToObject(item, "email", token_response->email) == NULL) {
    goto fail; //String
    }
    }


    // token_response->exchanges
    if(token_response->exchanges != upstox_client_token_response_EXCHANGES_NULL) {
    cJSON *exchanges = cJSON_AddArrayToObject(item, "exchanges");
    if(exchanges == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *exchangesListEntry;
    list_ForEach(exchangesListEntry, token_response->exchanges) {
    if(cJSON_AddStringToObject(exchanges, "", exchangesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // token_response->products
    if(token_response->products != upstox_client_token_response_PRODUCTS_NULL) {
    cJSON *products = cJSON_AddArrayToObject(item, "products");
    if(products == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *productsListEntry;
    list_ForEach(productsListEntry, token_response->products) {
    if(cJSON_AddStringToObject(products, "", productsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // token_response->broker
    if(token_response->broker) {
    if(cJSON_AddStringToObject(item, "broker", token_response->broker) == NULL) {
    goto fail; //String
    }
    }


    // token_response->user_id
    if(token_response->user_id) {
    if(cJSON_AddStringToObject(item, "user_id", token_response->user_id) == NULL) {
    goto fail; //String
    }
    }


    // token_response->user_name
    if(token_response->user_name) {
    if(cJSON_AddStringToObject(item, "user_name", token_response->user_name) == NULL) {
    goto fail; //String
    }
    }


    // token_response->order_types
    if(token_response->order_types != upstox_client_token_response_ORDERTYPES_NULL) {
    cJSON *order_types = cJSON_AddArrayToObject(item, "order_types");
    if(order_types == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *order_typesListEntry;
    list_ForEach(order_typesListEntry, token_response->order_types) {
    if(cJSON_AddStringToObject(order_types, "", order_typesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // token_response->user_type
    if(token_response->user_type) {
    if(cJSON_AddStringToObject(item, "user_type", token_response->user_type) == NULL) {
    goto fail; //String
    }
    }


    // token_response->poa
    if(token_response->poa) {
    if(cJSON_AddBoolToObject(item, "poa", *token_response->poa) == NULL) {
    goto fail; //Bool
    }
    }


    // token_response->ddpi
    if(token_response->ddpi) {
    if(cJSON_AddBoolToObject(item, "ddpi", *token_response->ddpi) == NULL) {
    goto fail; //Bool
    }
    }


    // token_response->is_active
    if(token_response->is_active) {
    if(cJSON_AddBoolToObject(item, "is_active", *token_response->is_active) == NULL) {
    goto fail; //Bool
    }
    }


    // token_response->access_token
    if(token_response->access_token) {
    if(cJSON_AddStringToObject(item, "access_token", token_response->access_token) == NULL) {
    goto fail; //String
    }
    }


    // token_response->extended_token
    if(token_response->extended_token) {
    if(cJSON_AddStringToObject(item, "extended_token", token_response->extended_token) == NULL) {
    goto fail; //String
    }
    }


    // token_response->expires_in
    if(token_response->expires_in) {
    if(cJSON_AddNumberToObject(item, "expires_in", *token_response->expires_in) == NULL) {
    goto fail; //Numeric
    }
    }


    // token_response->token_type
    if(token_response->token_type) {
    if(cJSON_AddStringToObject(item, "token_type", token_response->token_type) == NULL) {
    goto fail; //String
    }
    }


    // token_response->refresh_token
    if(token_response->refresh_token) {
    if(cJSON_AddStringToObject(item, "refresh_token", token_response->refresh_token) == NULL) {
    goto fail; //String
    }
    }


    // token_response->refresh_token_expires_in
    if(token_response->refresh_token_expires_in) {
    if(cJSON_AddNumberToObject(item, "refresh_token_expires_in", *token_response->refresh_token_expires_in) == NULL) {
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

token_response_t *token_response_parseFromJSON(cJSON *token_responseJSON){

    token_response_t *token_response_local_var = NULL;

    char *email_local_str = NULL;

    // define the local list for token_response->exchanges
    list_t *exchangesList = NULL;

    // define the local list for token_response->products
    list_t *productsList = NULL;

    char *broker_local_str = NULL;

    char *user_id_local_str = NULL;

    char *user_name_local_str = NULL;

    // define the local list for token_response->order_types
    list_t *order_typesList = NULL;

    char *user_type_local_str = NULL;

    // define the local variable for token_response->poa
    int *poa_local_var = NULL;

    // define the local variable for token_response->ddpi
    int *ddpi_local_var = NULL;

    // define the local variable for token_response->is_active
    int *is_active_local_var = NULL;

    char *access_token_local_str = NULL;

    char *extended_token_local_str = NULL;

    // define the local variable for token_response->expires_in
    int *expires_in_local_var = NULL;

    char *token_type_local_str = NULL;

    char *refresh_token_local_str = NULL;

    // define the local variable for token_response->refresh_token_expires_in
    int *refresh_token_expires_in_local_var = NULL;

    // token_response->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // token_response->exchanges
    cJSON *exchanges = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "exchanges");
    if (cJSON_IsNull(exchanges)) {
        exchanges = NULL;
    }
    if (exchanges) { 
    cJSON *exchanges_local = NULL;
    if(!cJSON_IsArray(exchanges)) {
        goto end;//primitive container
    }
    exchangesList = list_createList();

    cJSON_ArrayForEach(exchanges_local, exchanges)
    {
        if(!cJSON_IsString(exchanges_local))
        {
            goto end;
        }
        list_addElement(exchangesList , strdup(exchanges_local->valuestring));
    }
    }

    // token_response->products
    cJSON *products = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "products");
    if (cJSON_IsNull(products)) {
        products = NULL;
    }
    if (products) { 
    cJSON *products_local = NULL;
    if(!cJSON_IsArray(products)) {
        goto end;//primitive container
    }
    productsList = list_createList();

    cJSON_ArrayForEach(products_local, products)
    {
        if(!cJSON_IsString(products_local))
        {
            goto end;
        }
        list_addElement(productsList , strdup(products_local->valuestring));
    }
    }

    // token_response->broker
    cJSON *broker = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "broker");
    if (cJSON_IsNull(broker)) {
        broker = NULL;
    }
    if (broker) { 
    if(!cJSON_IsString(broker) && !cJSON_IsNull(broker))
    {
    goto end; //String
    }
    }

    // token_response->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (user_id) { 
    if(!cJSON_IsString(user_id) && !cJSON_IsNull(user_id))
    {
    goto end; //String
    }
    }

    // token_response->user_name
    cJSON *user_name = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "user_name");
    if (cJSON_IsNull(user_name)) {
        user_name = NULL;
    }
    if (user_name) { 
    if(!cJSON_IsString(user_name) && !cJSON_IsNull(user_name))
    {
    goto end; //String
    }
    }

    // token_response->order_types
    cJSON *order_types = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "order_types");
    if (cJSON_IsNull(order_types)) {
        order_types = NULL;
    }
    if (order_types) { 
    cJSON *order_types_local = NULL;
    if(!cJSON_IsArray(order_types)) {
        goto end;//primitive container
    }
    order_typesList = list_createList();

    cJSON_ArrayForEach(order_types_local, order_types)
    {
        if(!cJSON_IsString(order_types_local))
        {
            goto end;
        }
        list_addElement(order_typesList , strdup(order_types_local->valuestring));
    }
    }

    // token_response->user_type
    cJSON *user_type = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "user_type");
    if (cJSON_IsNull(user_type)) {
        user_type = NULL;
    }
    if (user_type) { 
    if(!cJSON_IsString(user_type) && !cJSON_IsNull(user_type))
    {
    goto end; //String
    }
    }

    // token_response->poa
    cJSON *poa = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "poa");
    if (cJSON_IsNull(poa)) {
        poa = NULL;
    }
    if (poa) { 
    if(!cJSON_IsBool(poa))
    {
    goto end; //Bool
    }
    poa_local_var = malloc(sizeof(int));
    if(!poa_local_var)
    {
        goto end;
    }
    *poa_local_var = poa->valueint;
    }

    // token_response->ddpi
    cJSON *ddpi = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "ddpi");
    if (cJSON_IsNull(ddpi)) {
        ddpi = NULL;
    }
    if (ddpi) { 
    if(!cJSON_IsBool(ddpi))
    {
    goto end; //Bool
    }
    ddpi_local_var = malloc(sizeof(int));
    if(!ddpi_local_var)
    {
        goto end;
    }
    *ddpi_local_var = ddpi->valueint;
    }

    // token_response->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "is_active");
    if (cJSON_IsNull(is_active)) {
        is_active = NULL;
    }
    if (is_active) { 
    if(!cJSON_IsBool(is_active))
    {
    goto end; //Bool
    }
    is_active_local_var = malloc(sizeof(int));
    if(!is_active_local_var)
    {
        goto end;
    }
    *is_active_local_var = is_active->valueint;
    }

    // token_response->access_token
    cJSON *access_token = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "access_token");
    if (cJSON_IsNull(access_token)) {
        access_token = NULL;
    }
    if (access_token) { 
    if(!cJSON_IsString(access_token) && !cJSON_IsNull(access_token))
    {
    goto end; //String
    }
    }

    // token_response->extended_token
    cJSON *extended_token = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "extended_token");
    if (cJSON_IsNull(extended_token)) {
        extended_token = NULL;
    }
    if (extended_token) { 
    if(!cJSON_IsString(extended_token) && !cJSON_IsNull(extended_token))
    {
    goto end; //String
    }
    }

    // token_response->expires_in
    cJSON *expires_in = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "expires_in");
    if (cJSON_IsNull(expires_in)) {
        expires_in = NULL;
    }
    if (expires_in) { 
    if(!cJSON_IsNumber(expires_in))
    {
    goto end; //Numeric
    }
    expires_in_local_var = malloc(sizeof(int));
    if(!expires_in_local_var)
    {
        goto end;
    }
    *expires_in_local_var = expires_in->valuedouble;
    }

    // token_response->token_type
    cJSON *token_type = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "token_type");
    if (cJSON_IsNull(token_type)) {
        token_type = NULL;
    }
    if (token_type) { 
    if(!cJSON_IsString(token_type) && !cJSON_IsNull(token_type))
    {
    goto end; //String
    }
    }

    // token_response->refresh_token
    cJSON *refresh_token = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "refresh_token");
    if (cJSON_IsNull(refresh_token)) {
        refresh_token = NULL;
    }
    if (refresh_token) { 
    if(!cJSON_IsString(refresh_token) && !cJSON_IsNull(refresh_token))
    {
    goto end; //String
    }
    }

    // token_response->refresh_token_expires_in
    cJSON *refresh_token_expires_in = cJSON_GetObjectItemCaseSensitive(token_responseJSON, "refresh_token_expires_in");
    if (cJSON_IsNull(refresh_token_expires_in)) {
        refresh_token_expires_in = NULL;
    }
    if (refresh_token_expires_in) { 
    if(!cJSON_IsNumber(refresh_token_expires_in))
    {
    goto end; //Numeric
    }
    refresh_token_expires_in_local_var = malloc(sizeof(int));
    if(!refresh_token_expires_in_local_var)
    {
        goto end;
    }
    *refresh_token_expires_in_local_var = refresh_token_expires_in->valuedouble;
    }


    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (broker && !cJSON_IsNull(broker)) broker_local_str = strdup(broker->valuestring);
    if (user_id && !cJSON_IsNull(user_id)) user_id_local_str = strdup(user_id->valuestring);
    if (user_name && !cJSON_IsNull(user_name)) user_name_local_str = strdup(user_name->valuestring);
    if (user_type && !cJSON_IsNull(user_type)) user_type_local_str = strdup(user_type->valuestring);
    if (access_token && !cJSON_IsNull(access_token)) access_token_local_str = strdup(access_token->valuestring);
    if (extended_token && !cJSON_IsNull(extended_token)) extended_token_local_str = strdup(extended_token->valuestring);
    if (token_type && !cJSON_IsNull(token_type)) token_type_local_str = strdup(token_type->valuestring);
    if (refresh_token && !cJSON_IsNull(refresh_token)) refresh_token_local_str = strdup(refresh_token->valuestring);

    token_response_local_var = token_response_create_internal (
        email_local_str,
        exchanges ? exchangesList : NULL,
        products ? productsList : NULL,
        broker_local_str,
        user_id_local_str,
        user_name_local_str,
        order_types ? order_typesList : NULL,
        user_type_local_str,
        poa_local_var,
        ddpi_local_var,
        is_active_local_var,
        access_token_local_str,
        extended_token_local_str,
        expires_in_local_var,
        token_type_local_str,
        refresh_token_local_str,
        refresh_token_expires_in_local_var
        );

    if (!token_response_local_var) {
        goto end;
    }

    return token_response_local_var;
end:
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (exchangesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, exchangesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(exchangesList);
        exchangesList = NULL;
    }
    if (productsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, productsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(productsList);
        productsList = NULL;
    }
    if (broker_local_str) {
        free(broker_local_str);
        broker_local_str = NULL;
    }
    if (user_id_local_str) {
        free(user_id_local_str);
        user_id_local_str = NULL;
    }
    if (user_name_local_str) {
        free(user_name_local_str);
        user_name_local_str = NULL;
    }
    if (order_typesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, order_typesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(order_typesList);
        order_typesList = NULL;
    }
    if (user_type_local_str) {
        free(user_type_local_str);
        user_type_local_str = NULL;
    }
    if (poa_local_var) {
        free(poa_local_var);
        poa_local_var = NULL;
    }
    if (ddpi_local_var) {
        free(ddpi_local_var);
        ddpi_local_var = NULL;
    }
    if (is_active_local_var) {
        free(is_active_local_var);
        is_active_local_var = NULL;
    }
    if (access_token_local_str) {
        free(access_token_local_str);
        access_token_local_str = NULL;
    }
    if (extended_token_local_str) {
        free(extended_token_local_str);
        extended_token_local_str = NULL;
    }
    if (expires_in_local_var) {
        free(expires_in_local_var);
        expires_in_local_var = NULL;
    }
    if (token_type_local_str) {
        free(token_type_local_str);
        token_type_local_str = NULL;
    }
    if (refresh_token_local_str) {
        free(refresh_token_local_str);
        refresh_token_local_str = NULL;
    }
    if (refresh_token_expires_in_local_var) {
        free(refresh_token_expires_in_local_var);
        refresh_token_expires_in_local_var = NULL;
    }
    return NULL;

}
