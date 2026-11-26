#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "profile_data.h"


char* profile_data_exchanges_ToString(upstox_client_profile_data_EXCHANGES_e exchanges) {
    char *exchangesArray[] =  { "NULL", "NSE", "NFO", "CDS", "BSE", "BFO", "BCD", "MCX", "NSCOM", "NSE_EG" };
    return exchangesArray[exchanges - 1];
}

upstox_client_profile_data_EXCHANGES_e profile_data_exchanges_FromString(char* exchanges) {
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
char* profile_data_products_ToString(upstox_client_profile_data_PRODUCTS_e products) {
    char *productsArray[] =  { "NULL", "I", "D", "CO", "OCO", "MTF" };
    return productsArray[products - 1];
}

upstox_client_profile_data_PRODUCTS_e profile_data_products_FromString(char* products) {
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
char* profile_data_order_types_ToString(upstox_client_profile_data_ORDERTYPES_e order_types) {
    char *order_typesArray[] =  { "NULL", "MARKET", "LIMIT", "SL", "SL-M" };
    return order_typesArray[order_types - 1];
}

upstox_client_profile_data_ORDERTYPES_e profile_data_order_types_FromString(char* order_types) {
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

static profile_data_t *profile_data_create_internal(
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
    int *is_active
    ) {
    profile_data_t *profile_data_local_var = malloc(sizeof(profile_data_t));
    if (!profile_data_local_var) {
        return NULL;
    }
    memset(profile_data_local_var, 0, sizeof(profile_data_t));
    profile_data_local_var->_library_owned = 1;
    profile_data_local_var->email = email;
    profile_data_local_var->exchanges = exchanges;
    profile_data_local_var->products = products;
    profile_data_local_var->broker = broker;
    profile_data_local_var->user_id = user_id;
    profile_data_local_var->user_name = user_name;
    profile_data_local_var->order_types = order_types;
    profile_data_local_var->user_type = user_type;
    profile_data_local_var->poa = poa;
    profile_data_local_var->ddpi = ddpi;
    profile_data_local_var->is_active = is_active;
    return profile_data_local_var;
}

profile_data_t *profile_data_create(
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
    int *is_active
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
    profile_data_t *result = profile_data_create_internal (
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
        is_active_copy
        );
    if (!result) {
        free(poa_copy);
        free(ddpi_copy);
        free(is_active_copy);
    }
    return result;
}

void profile_data_free(profile_data_t *profile_data) {
    if(NULL == profile_data){
        return ;
    }
    if(profile_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "profile_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (profile_data->email) {
        free(profile_data->email);
        profile_data->email = NULL;
    }
    if (profile_data->exchanges) {
        list_ForEach(listEntry, profile_data->exchanges) {
            free(listEntry->data);
        }
        list_freeList(profile_data->exchanges);
        profile_data->exchanges = NULL;
    }
    if (profile_data->products) {
        list_ForEach(listEntry, profile_data->products) {
            free(listEntry->data);
        }
        list_freeList(profile_data->products);
        profile_data->products = NULL;
    }
    if (profile_data->broker) {
        free(profile_data->broker);
        profile_data->broker = NULL;
    }
    if (profile_data->user_id) {
        free(profile_data->user_id);
        profile_data->user_id = NULL;
    }
    if (profile_data->user_name) {
        free(profile_data->user_name);
        profile_data->user_name = NULL;
    }
    if (profile_data->order_types) {
        list_ForEach(listEntry, profile_data->order_types) {
            free(listEntry->data);
        }
        list_freeList(profile_data->order_types);
        profile_data->order_types = NULL;
    }
    if (profile_data->user_type) {
        free(profile_data->user_type);
        profile_data->user_type = NULL;
    }
    if (profile_data->poa) {
        free(profile_data->poa);
        profile_data->poa = NULL;
    }
    if (profile_data->ddpi) {
        free(profile_data->ddpi);
        profile_data->ddpi = NULL;
    }
    if (profile_data->is_active) {
        free(profile_data->is_active);
        profile_data->is_active = NULL;
    }
    free(profile_data);
}

cJSON *profile_data_convertToJSON(profile_data_t *profile_data) {
    cJSON *item = cJSON_CreateObject();

    // profile_data->email
    if(profile_data->email) {
    if(cJSON_AddStringToObject(item, "email", profile_data->email) == NULL) {
    goto fail; //String
    }
    }


    // profile_data->exchanges
    if(profile_data->exchanges != upstox_client_profile_data_EXCHANGES_NULL) {
    cJSON *exchanges = cJSON_AddArrayToObject(item, "exchanges");
    if(exchanges == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *exchangesListEntry;
    list_ForEach(exchangesListEntry, profile_data->exchanges) {
    if(cJSON_AddStringToObject(exchanges, "", exchangesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // profile_data->products
    if(profile_data->products != upstox_client_profile_data_PRODUCTS_NULL) {
    cJSON *products = cJSON_AddArrayToObject(item, "products");
    if(products == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *productsListEntry;
    list_ForEach(productsListEntry, profile_data->products) {
    if(cJSON_AddStringToObject(products, "", productsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // profile_data->broker
    if(profile_data->broker) {
    if(cJSON_AddStringToObject(item, "broker", profile_data->broker) == NULL) {
    goto fail; //String
    }
    }


    // profile_data->user_id
    if(profile_data->user_id) {
    if(cJSON_AddStringToObject(item, "user_id", profile_data->user_id) == NULL) {
    goto fail; //String
    }
    }


    // profile_data->user_name
    if(profile_data->user_name) {
    if(cJSON_AddStringToObject(item, "user_name", profile_data->user_name) == NULL) {
    goto fail; //String
    }
    }


    // profile_data->order_types
    if(profile_data->order_types != upstox_client_profile_data_ORDERTYPES_NULL) {
    cJSON *order_types = cJSON_AddArrayToObject(item, "order_types");
    if(order_types == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *order_typesListEntry;
    list_ForEach(order_typesListEntry, profile_data->order_types) {
    if(cJSON_AddStringToObject(order_types, "", order_typesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // profile_data->user_type
    if(profile_data->user_type) {
    if(cJSON_AddStringToObject(item, "user_type", profile_data->user_type) == NULL) {
    goto fail; //String
    }
    }


    // profile_data->poa
    if(profile_data->poa) {
    if(cJSON_AddBoolToObject(item, "poa", *profile_data->poa) == NULL) {
    goto fail; //Bool
    }
    }


    // profile_data->ddpi
    if(profile_data->ddpi) {
    if(cJSON_AddBoolToObject(item, "ddpi", *profile_data->ddpi) == NULL) {
    goto fail; //Bool
    }
    }


    // profile_data->is_active
    if(profile_data->is_active) {
    if(cJSON_AddBoolToObject(item, "is_active", *profile_data->is_active) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

profile_data_t *profile_data_parseFromJSON(cJSON *profile_dataJSON){

    profile_data_t *profile_data_local_var = NULL;

    char *email_local_str = NULL;

    // define the local list for profile_data->exchanges
    list_t *exchangesList = NULL;

    // define the local list for profile_data->products
    list_t *productsList = NULL;

    char *broker_local_str = NULL;

    char *user_id_local_str = NULL;

    char *user_name_local_str = NULL;

    // define the local list for profile_data->order_types
    list_t *order_typesList = NULL;

    char *user_type_local_str = NULL;

    // define the local variable for profile_data->poa
    int *poa_local_var = NULL;

    // define the local variable for profile_data->ddpi
    int *ddpi_local_var = NULL;

    // define the local variable for profile_data->is_active
    int *is_active_local_var = NULL;

    // profile_data->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(profile_dataJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // profile_data->exchanges
    cJSON *exchanges = cJSON_GetObjectItemCaseSensitive(profile_dataJSON, "exchanges");
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

    // profile_data->products
    cJSON *products = cJSON_GetObjectItemCaseSensitive(profile_dataJSON, "products");
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

    // profile_data->broker
    cJSON *broker = cJSON_GetObjectItemCaseSensitive(profile_dataJSON, "broker");
    if (cJSON_IsNull(broker)) {
        broker = NULL;
    }
    if (broker) { 
    if(!cJSON_IsString(broker) && !cJSON_IsNull(broker))
    {
    goto end; //String
    }
    }

    // profile_data->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(profile_dataJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (user_id) { 
    if(!cJSON_IsString(user_id) && !cJSON_IsNull(user_id))
    {
    goto end; //String
    }
    }

    // profile_data->user_name
    cJSON *user_name = cJSON_GetObjectItemCaseSensitive(profile_dataJSON, "user_name");
    if (cJSON_IsNull(user_name)) {
        user_name = NULL;
    }
    if (user_name) { 
    if(!cJSON_IsString(user_name) && !cJSON_IsNull(user_name))
    {
    goto end; //String
    }
    }

    // profile_data->order_types
    cJSON *order_types = cJSON_GetObjectItemCaseSensitive(profile_dataJSON, "order_types");
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

    // profile_data->user_type
    cJSON *user_type = cJSON_GetObjectItemCaseSensitive(profile_dataJSON, "user_type");
    if (cJSON_IsNull(user_type)) {
        user_type = NULL;
    }
    if (user_type) { 
    if(!cJSON_IsString(user_type) && !cJSON_IsNull(user_type))
    {
    goto end; //String
    }
    }

    // profile_data->poa
    cJSON *poa = cJSON_GetObjectItemCaseSensitive(profile_dataJSON, "poa");
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

    // profile_data->ddpi
    cJSON *ddpi = cJSON_GetObjectItemCaseSensitive(profile_dataJSON, "ddpi");
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

    // profile_data->is_active
    cJSON *is_active = cJSON_GetObjectItemCaseSensitive(profile_dataJSON, "is_active");
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


    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (broker && !cJSON_IsNull(broker)) broker_local_str = strdup(broker->valuestring);
    if (user_id && !cJSON_IsNull(user_id)) user_id_local_str = strdup(user_id->valuestring);
    if (user_name && !cJSON_IsNull(user_name)) user_name_local_str = strdup(user_name->valuestring);
    if (user_type && !cJSON_IsNull(user_type)) user_type_local_str = strdup(user_type->valuestring);

    profile_data_local_var = profile_data_create_internal (
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
        is_active_local_var
        );

    if (!profile_data_local_var) {
        goto end;
    }

    return profile_data_local_var;
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
    return NULL;

}
