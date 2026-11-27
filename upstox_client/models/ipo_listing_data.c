#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_listing_data.h"


char* ipo_listing_data_status_ToString(upstox_client_ipo_listing_data_STATUS_e status) {
    char* statusArray[] =  { "NULL", "open", "closed", "listed", "upcoming" };
    return statusArray[status];
}

upstox_client_ipo_listing_data_STATUS_e ipo_listing_data_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "open", "closed", "listed", "upcoming" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* ipo_listing_data_issue_type_ToString(upstox_client_ipo_listing_data_ISSUETYPE_e issue_type) {
    char* issue_typeArray[] =  { "NULL", "regular", "sme" };
    return issue_typeArray[issue_type];
}

upstox_client_ipo_listing_data_ISSUETYPE_e ipo_listing_data_issue_type_FromString(char* issue_type){
    int stringToReturn = 0;
    char *issue_typeArray[] =  { "NULL", "regular", "sme" };
    size_t sizeofArray = sizeof(issue_typeArray) / sizeof(issue_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(issue_type, issue_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static ipo_listing_data_t *ipo_listing_data_create_internal(
    char *id,
    char *symbol,
    char *name,
    upstox_client_ipo_listing_data_STATUS_e status,
    char *isin,
    upstox_client_ipo_listing_data_ISSUETYPE_e issue_type,
    double *issue_size,
    char *industry,
    double *minimum_price,
    double *maximum_price,
    char *bidding_start_date,
    char *bidding_end_date,
    char *total_subscription,
    list_t *investors
    ) {
    ipo_listing_data_t *ipo_listing_data_local_var = malloc(sizeof(ipo_listing_data_t));
    if (!ipo_listing_data_local_var) {
        return NULL;
    }
    memset(ipo_listing_data_local_var, 0, sizeof(ipo_listing_data_t));
    ipo_listing_data_local_var->_library_owned = 1;
    ipo_listing_data_local_var->id = id;
    ipo_listing_data_local_var->symbol = symbol;
    ipo_listing_data_local_var->name = name;
    ipo_listing_data_local_var->status = status;
    ipo_listing_data_local_var->isin = isin;
    ipo_listing_data_local_var->issue_type = issue_type;
    ipo_listing_data_local_var->issue_size = issue_size;
    ipo_listing_data_local_var->industry = industry;
    ipo_listing_data_local_var->minimum_price = minimum_price;
    ipo_listing_data_local_var->maximum_price = maximum_price;
    ipo_listing_data_local_var->bidding_start_date = bidding_start_date;
    ipo_listing_data_local_var->bidding_end_date = bidding_end_date;
    ipo_listing_data_local_var->total_subscription = total_subscription;
    ipo_listing_data_local_var->investors = investors;
    return ipo_listing_data_local_var;
}

ipo_listing_data_t *ipo_listing_data_create(
    char *id,
    char *symbol,
    char *name,
    upstox_client_ipo_listing_data_STATUS_e status,
    char *isin,
    upstox_client_ipo_listing_data_ISSUETYPE_e issue_type,
    double *issue_size,
    char *industry,
    double *minimum_price,
    double *maximum_price,
    char *bidding_start_date,
    char *bidding_end_date,
    char *total_subscription,
    list_t *investors
    ) {
    double *issue_size_copy = NULL;
    if (issue_size) {
        issue_size_copy = malloc(sizeof(double));
        if (issue_size_copy) *issue_size_copy = *issue_size;
    }
    double *minimum_price_copy = NULL;
    if (minimum_price) {
        minimum_price_copy = malloc(sizeof(double));
        if (minimum_price_copy) *minimum_price_copy = *minimum_price;
    }
    double *maximum_price_copy = NULL;
    if (maximum_price) {
        maximum_price_copy = malloc(sizeof(double));
        if (maximum_price_copy) *maximum_price_copy = *maximum_price;
    }
    ipo_listing_data_t *result = ipo_listing_data_create_internal (
        id,
        symbol,
        name,
        status,
        isin,
        issue_type,
        issue_size_copy,
        industry,
        minimum_price_copy,
        maximum_price_copy,
        bidding_start_date,
        bidding_end_date,
        total_subscription,
        investors
        );
    if (!result) {
        free(issue_size_copy);
        free(minimum_price_copy);
        free(maximum_price_copy);
    }
    return result;
}

void ipo_listing_data_free(ipo_listing_data_t *ipo_listing_data) {
    if(NULL == ipo_listing_data){
        return ;
    }
    if(ipo_listing_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_listing_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_listing_data->id) {
        free(ipo_listing_data->id);
        ipo_listing_data->id = NULL;
    }
    if (ipo_listing_data->symbol) {
        free(ipo_listing_data->symbol);
        ipo_listing_data->symbol = NULL;
    }
    if (ipo_listing_data->name) {
        free(ipo_listing_data->name);
        ipo_listing_data->name = NULL;
    }
    if (ipo_listing_data->isin) {
        free(ipo_listing_data->isin);
        ipo_listing_data->isin = NULL;
    }
    if (ipo_listing_data->issue_size) {
        free(ipo_listing_data->issue_size);
        ipo_listing_data->issue_size = NULL;
    }
    if (ipo_listing_data->industry) {
        free(ipo_listing_data->industry);
        ipo_listing_data->industry = NULL;
    }
    if (ipo_listing_data->minimum_price) {
        free(ipo_listing_data->minimum_price);
        ipo_listing_data->minimum_price = NULL;
    }
    if (ipo_listing_data->maximum_price) {
        free(ipo_listing_data->maximum_price);
        ipo_listing_data->maximum_price = NULL;
    }
    if (ipo_listing_data->bidding_start_date) {
        free(ipo_listing_data->bidding_start_date);
        ipo_listing_data->bidding_start_date = NULL;
    }
    if (ipo_listing_data->bidding_end_date) {
        free(ipo_listing_data->bidding_end_date);
        ipo_listing_data->bidding_end_date = NULL;
    }
    if (ipo_listing_data->total_subscription) {
        free(ipo_listing_data->total_subscription);
        ipo_listing_data->total_subscription = NULL;
    }
    if (ipo_listing_data->investors) {
        list_ForEach(listEntry, ipo_listing_data->investors) {
            ipo_investor_type_free(listEntry->data);
        }
        list_freeList(ipo_listing_data->investors);
        ipo_listing_data->investors = NULL;
    }
    free(ipo_listing_data);
}

cJSON *ipo_listing_data_convertToJSON(ipo_listing_data_t *ipo_listing_data) {
    cJSON *item = cJSON_CreateObject();

    // ipo_listing_data->id
    if(ipo_listing_data->id) {
    if(cJSON_AddStringToObject(item, "id", ipo_listing_data->id) == NULL) {
    goto fail; //String
    }
    }


    // ipo_listing_data->symbol
    if(ipo_listing_data->symbol) {
    if(cJSON_AddStringToObject(item, "symbol", ipo_listing_data->symbol) == NULL) {
    goto fail; //String
    }
    }


    // ipo_listing_data->name
    if(ipo_listing_data->name) {
    if(cJSON_AddStringToObject(item, "name", ipo_listing_data->name) == NULL) {
    goto fail; //String
    }
    }


    // ipo_listing_data->status
    if(ipo_listing_data->status != upstox_client_ipo_listing_data_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", ipo_listing_data_status_ToString(ipo_listing_data->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // ipo_listing_data->isin
    if(ipo_listing_data->isin) {
    if(cJSON_AddStringToObject(item, "isin", ipo_listing_data->isin) == NULL) {
    goto fail; //String
    }
    }


    // ipo_listing_data->issue_type
    if(ipo_listing_data->issue_type != upstox_client_ipo_listing_data_ISSUETYPE_NULL) {
    if(cJSON_AddStringToObject(item, "issue_type", ipo_listing_data_issue_type_ToString(ipo_listing_data->issue_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // ipo_listing_data->issue_size
    if(ipo_listing_data->issue_size) {
    if(cJSON_AddNumberToObject(item, "issue_size", *ipo_listing_data->issue_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_listing_data->industry
    if(ipo_listing_data->industry) {
    if(cJSON_AddStringToObject(item, "industry", ipo_listing_data->industry) == NULL) {
    goto fail; //String
    }
    }


    // ipo_listing_data->minimum_price
    if(ipo_listing_data->minimum_price) {
    if(cJSON_AddNumberToObject(item, "minimum_price", *ipo_listing_data->minimum_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_listing_data->maximum_price
    if(ipo_listing_data->maximum_price) {
    if(cJSON_AddNumberToObject(item, "maximum_price", *ipo_listing_data->maximum_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_listing_data->bidding_start_date
    if(ipo_listing_data->bidding_start_date) {
    if(cJSON_AddStringToObject(item, "bidding_start_date", ipo_listing_data->bidding_start_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_listing_data->bidding_end_date
    if(ipo_listing_data->bidding_end_date) {
    if(cJSON_AddStringToObject(item, "bidding_end_date", ipo_listing_data->bidding_end_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_listing_data->total_subscription
    if(ipo_listing_data->total_subscription) {
    if(cJSON_AddStringToObject(item, "total_subscription", ipo_listing_data->total_subscription) == NULL) {
    goto fail; //String
    }
    }


    // ipo_listing_data->investors
    if(ipo_listing_data->investors) {
    cJSON *investors = cJSON_AddArrayToObject(item, "investors");
    if(investors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *investorsListEntry;
    if (ipo_listing_data->investors) {
    list_ForEach(investorsListEntry, ipo_listing_data->investors) {
    cJSON *itemLocal = ipo_investor_type_convertToJSON(investorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(investors, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ipo_listing_data_t *ipo_listing_data_parseFromJSON(cJSON *ipo_listing_dataJSON){

    ipo_listing_data_t *ipo_listing_data_local_var = NULL;

    char *id_local_str = NULL;

    char *symbol_local_str = NULL;

    char *name_local_str = NULL;

    char *isin_local_str = NULL;

    // define the local variable for ipo_listing_data->issue_size
    double *issue_size_local_var = NULL;

    char *industry_local_str = NULL;

    // define the local variable for ipo_listing_data->minimum_price
    double *minimum_price_local_var = NULL;

    // define the local variable for ipo_listing_data->maximum_price
    double *maximum_price_local_var = NULL;

    char *bidding_start_date_local_str = NULL;

    char *bidding_end_date_local_str = NULL;

    char *total_subscription_local_str = NULL;

    // define the local list for ipo_listing_data->investors
    list_t *investorsList = NULL;

    // ipo_listing_data->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // ipo_listing_data->symbol
    cJSON *symbol = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "symbol");
    if (cJSON_IsNull(symbol)) {
        symbol = NULL;
    }
    if (symbol) { 
    if(!cJSON_IsString(symbol) && !cJSON_IsNull(symbol))
    {
    goto end; //String
    }
    }

    // ipo_listing_data->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // ipo_listing_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_ipo_listing_data_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = ipo_listing_data_status_FromString(status->valuestring);
    }

    // ipo_listing_data->isin
    cJSON *isin = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "isin");
    if (cJSON_IsNull(isin)) {
        isin = NULL;
    }
    if (isin) { 
    if(!cJSON_IsString(isin) && !cJSON_IsNull(isin))
    {
    goto end; //String
    }
    }

    // ipo_listing_data->issue_type
    cJSON *issue_type = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "issue_type");
    if (cJSON_IsNull(issue_type)) {
        issue_type = NULL;
    }
    upstox_client_ipo_listing_data_ISSUETYPE_e issue_typeVariable;
    if (issue_type) { 
    if(!cJSON_IsString(issue_type))
    {
    goto end; //Enum
    }
    issue_typeVariable = ipo_listing_data_issue_type_FromString(issue_type->valuestring);
    }

    // ipo_listing_data->issue_size
    cJSON *issue_size = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "issue_size");
    if (cJSON_IsNull(issue_size)) {
        issue_size = NULL;
    }
    if (issue_size) { 
    if(!cJSON_IsNumber(issue_size))
    {
    goto end; //Numeric
    }
    issue_size_local_var = malloc(sizeof(double));
    if(!issue_size_local_var)
    {
        goto end;
    }
    *issue_size_local_var = issue_size->valuedouble;
    }

    // ipo_listing_data->industry
    cJSON *industry = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "industry");
    if (cJSON_IsNull(industry)) {
        industry = NULL;
    }
    if (industry) { 
    if(!cJSON_IsString(industry) && !cJSON_IsNull(industry))
    {
    goto end; //String
    }
    }

    // ipo_listing_data->minimum_price
    cJSON *minimum_price = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "minimum_price");
    if (cJSON_IsNull(minimum_price)) {
        minimum_price = NULL;
    }
    if (minimum_price) { 
    if(!cJSON_IsNumber(minimum_price))
    {
    goto end; //Numeric
    }
    minimum_price_local_var = malloc(sizeof(double));
    if(!minimum_price_local_var)
    {
        goto end;
    }
    *minimum_price_local_var = minimum_price->valuedouble;
    }

    // ipo_listing_data->maximum_price
    cJSON *maximum_price = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "maximum_price");
    if (cJSON_IsNull(maximum_price)) {
        maximum_price = NULL;
    }
    if (maximum_price) { 
    if(!cJSON_IsNumber(maximum_price))
    {
    goto end; //Numeric
    }
    maximum_price_local_var = malloc(sizeof(double));
    if(!maximum_price_local_var)
    {
        goto end;
    }
    *maximum_price_local_var = maximum_price->valuedouble;
    }

    // ipo_listing_data->bidding_start_date
    cJSON *bidding_start_date = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "bidding_start_date");
    if (cJSON_IsNull(bidding_start_date)) {
        bidding_start_date = NULL;
    }
    if (bidding_start_date) { 
    if(!cJSON_IsString(bidding_start_date) && !cJSON_IsNull(bidding_start_date))
    {
    goto end; //String
    }
    }

    // ipo_listing_data->bidding_end_date
    cJSON *bidding_end_date = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "bidding_end_date");
    if (cJSON_IsNull(bidding_end_date)) {
        bidding_end_date = NULL;
    }
    if (bidding_end_date) { 
    if(!cJSON_IsString(bidding_end_date) && !cJSON_IsNull(bidding_end_date))
    {
    goto end; //String
    }
    }

    // ipo_listing_data->total_subscription
    cJSON *total_subscription = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "total_subscription");
    if (cJSON_IsNull(total_subscription)) {
        total_subscription = NULL;
    }
    if (total_subscription) { 
    if(!cJSON_IsString(total_subscription) && !cJSON_IsNull(total_subscription))
    {
    goto end; //String
    }
    }

    // ipo_listing_data->investors
    cJSON *investors = cJSON_GetObjectItemCaseSensitive(ipo_listing_dataJSON, "investors");
    if (cJSON_IsNull(investors)) {
        investors = NULL;
    }
    if (investors) { 
    cJSON *investors_local_nonprimitive = NULL;
    if(!cJSON_IsArray(investors)){
        goto end; //nonprimitive container
    }

    investorsList = list_createList();

    cJSON_ArrayForEach(investors_local_nonprimitive,investors )
    {
        if(!cJSON_IsObject(investors_local_nonprimitive)){
            goto end;
        }
        ipo_investor_type_t *investorsItem = ipo_investor_type_parseFromJSON(investors_local_nonprimitive);

        list_addElement(investorsList, investorsItem);
    }
    }


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (symbol && !cJSON_IsNull(symbol)) symbol_local_str = strdup(symbol->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (isin && !cJSON_IsNull(isin)) isin_local_str = strdup(isin->valuestring);
    if (industry && !cJSON_IsNull(industry)) industry_local_str = strdup(industry->valuestring);
    if (bidding_start_date && !cJSON_IsNull(bidding_start_date)) bidding_start_date_local_str = strdup(bidding_start_date->valuestring);
    if (bidding_end_date && !cJSON_IsNull(bidding_end_date)) bidding_end_date_local_str = strdup(bidding_end_date->valuestring);
    if (total_subscription && !cJSON_IsNull(total_subscription)) total_subscription_local_str = strdup(total_subscription->valuestring);

    ipo_listing_data_local_var = ipo_listing_data_create_internal (
        id_local_str,
        symbol_local_str,
        name_local_str,
        status ? statusVariable : upstox_client_ipo_listing_data_STATUS_NULL,
        isin_local_str,
        issue_type ? issue_typeVariable : upstox_client_ipo_listing_data_ISSUETYPE_NULL,
        issue_size_local_var,
        industry_local_str,
        minimum_price_local_var,
        maximum_price_local_var,
        bidding_start_date_local_str,
        bidding_end_date_local_str,
        total_subscription_local_str,
        investors ? investorsList : NULL
        );

    if (!ipo_listing_data_local_var) {
        goto end;
    }

    return ipo_listing_data_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (symbol_local_str) {
        free(symbol_local_str);
        symbol_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (isin_local_str) {
        free(isin_local_str);
        isin_local_str = NULL;
    }
    if (issue_size_local_var) {
        free(issue_size_local_var);
        issue_size_local_var = NULL;
    }
    if (industry_local_str) {
        free(industry_local_str);
        industry_local_str = NULL;
    }
    if (minimum_price_local_var) {
        free(minimum_price_local_var);
        minimum_price_local_var = NULL;
    }
    if (maximum_price_local_var) {
        free(maximum_price_local_var);
        maximum_price_local_var = NULL;
    }
    if (bidding_start_date_local_str) {
        free(bidding_start_date_local_str);
        bidding_start_date_local_str = NULL;
    }
    if (bidding_end_date_local_str) {
        free(bidding_end_date_local_str);
        bidding_end_date_local_str = NULL;
    }
    if (total_subscription_local_str) {
        free(total_subscription_local_str);
        total_subscription_local_str = NULL;
    }
    if (investorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, investorsList) {
            ipo_investor_type_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(investorsList);
        investorsList = NULL;
    }
    return NULL;

}
