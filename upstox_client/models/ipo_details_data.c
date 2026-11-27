#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_details_data.h"


char* ipo_details_data_status_ToString(upstox_client_ipo_details_data_STATUS_e status) {
    char* statusArray[] =  { "NULL", "open", "closed", "listed", "upcoming" };
    return statusArray[status];
}

upstox_client_ipo_details_data_STATUS_e ipo_details_data_status_FromString(char* status){
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
char* ipo_details_data_issue_type_ToString(upstox_client_ipo_details_data_ISSUETYPE_e issue_type) {
    char* issue_typeArray[] =  { "NULL", "regular", "sme" };
    return issue_typeArray[issue_type];
}

upstox_client_ipo_details_data_ISSUETYPE_e ipo_details_data_issue_type_FromString(char* issue_type){
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

static ipo_details_data_t *ipo_details_data_create_internal(
    char *id,
    char *symbol,
    char *name,
    upstox_client_ipo_details_data_STATUS_e status,
    char *isin,
    upstox_client_ipo_details_data_ISSUETYPE_e issue_type,
    double *issue_size,
    char *industry,
    double *minimum_price,
    double *maximum_price,
    char *bidding_start_date,
    char *bidding_end_date,
    char *daily_start_time,
    char *daily_end_time,
    double *face_value,
    double *tick_size,
    int *lot_size,
    int *minimum_quantity,
    double *cut_off_price,
    double *listing_price,
    char *listing_exchange,
    char *rhp_url,
    char *drhp_url,
    ipo_timeline_t *timeline,
    ipo_registrar_info_t *registrar_info,
    char *total_subscription,
    list_t *investors
    ) {
    ipo_details_data_t *ipo_details_data_local_var = malloc(sizeof(ipo_details_data_t));
    if (!ipo_details_data_local_var) {
        return NULL;
    }
    memset(ipo_details_data_local_var, 0, sizeof(ipo_details_data_t));
    ipo_details_data_local_var->_library_owned = 1;
    ipo_details_data_local_var->id = id;
    ipo_details_data_local_var->symbol = symbol;
    ipo_details_data_local_var->name = name;
    ipo_details_data_local_var->status = status;
    ipo_details_data_local_var->isin = isin;
    ipo_details_data_local_var->issue_type = issue_type;
    ipo_details_data_local_var->issue_size = issue_size;
    ipo_details_data_local_var->industry = industry;
    ipo_details_data_local_var->minimum_price = minimum_price;
    ipo_details_data_local_var->maximum_price = maximum_price;
    ipo_details_data_local_var->bidding_start_date = bidding_start_date;
    ipo_details_data_local_var->bidding_end_date = bidding_end_date;
    ipo_details_data_local_var->daily_start_time = daily_start_time;
    ipo_details_data_local_var->daily_end_time = daily_end_time;
    ipo_details_data_local_var->face_value = face_value;
    ipo_details_data_local_var->tick_size = tick_size;
    ipo_details_data_local_var->lot_size = lot_size;
    ipo_details_data_local_var->minimum_quantity = minimum_quantity;
    ipo_details_data_local_var->cut_off_price = cut_off_price;
    ipo_details_data_local_var->listing_price = listing_price;
    ipo_details_data_local_var->listing_exchange = listing_exchange;
    ipo_details_data_local_var->rhp_url = rhp_url;
    ipo_details_data_local_var->drhp_url = drhp_url;
    ipo_details_data_local_var->timeline = timeline;
    ipo_details_data_local_var->registrar_info = registrar_info;
    ipo_details_data_local_var->total_subscription = total_subscription;
    ipo_details_data_local_var->investors = investors;
    return ipo_details_data_local_var;
}

ipo_details_data_t *ipo_details_data_create(
    char *id,
    char *symbol,
    char *name,
    upstox_client_ipo_details_data_STATUS_e status,
    char *isin,
    upstox_client_ipo_details_data_ISSUETYPE_e issue_type,
    double *issue_size,
    char *industry,
    double *minimum_price,
    double *maximum_price,
    char *bidding_start_date,
    char *bidding_end_date,
    char *daily_start_time,
    char *daily_end_time,
    double *face_value,
    double *tick_size,
    int *lot_size,
    int *minimum_quantity,
    double *cut_off_price,
    double *listing_price,
    char *listing_exchange,
    char *rhp_url,
    char *drhp_url,
    ipo_timeline_t *timeline,
    ipo_registrar_info_t *registrar_info,
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
    double *face_value_copy = NULL;
    if (face_value) {
        face_value_copy = malloc(sizeof(double));
        if (face_value_copy) *face_value_copy = *face_value;
    }
    double *tick_size_copy = NULL;
    if (tick_size) {
        tick_size_copy = malloc(sizeof(double));
        if (tick_size_copy) *tick_size_copy = *tick_size;
    }
    int *lot_size_copy = NULL;
    if (lot_size) {
        lot_size_copy = malloc(sizeof(int));
        if (lot_size_copy) *lot_size_copy = *lot_size;
    }
    int *minimum_quantity_copy = NULL;
    if (minimum_quantity) {
        minimum_quantity_copy = malloc(sizeof(int));
        if (minimum_quantity_copy) *minimum_quantity_copy = *minimum_quantity;
    }
    double *cut_off_price_copy = NULL;
    if (cut_off_price) {
        cut_off_price_copy = malloc(sizeof(double));
        if (cut_off_price_copy) *cut_off_price_copy = *cut_off_price;
    }
    double *listing_price_copy = NULL;
    if (listing_price) {
        listing_price_copy = malloc(sizeof(double));
        if (listing_price_copy) *listing_price_copy = *listing_price;
    }
    ipo_details_data_t *result = ipo_details_data_create_internal (
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
        daily_start_time,
        daily_end_time,
        face_value_copy,
        tick_size_copy,
        lot_size_copy,
        minimum_quantity_copy,
        cut_off_price_copy,
        listing_price_copy,
        listing_exchange,
        rhp_url,
        drhp_url,
        timeline,
        registrar_info,
        total_subscription,
        investors
        );
    if (!result) {
        free(issue_size_copy);
        free(minimum_price_copy);
        free(maximum_price_copy);
        free(face_value_copy);
        free(tick_size_copy);
        free(lot_size_copy);
        free(minimum_quantity_copy);
        free(cut_off_price_copy);
        free(listing_price_copy);
    }
    return result;
}

void ipo_details_data_free(ipo_details_data_t *ipo_details_data) {
    if(NULL == ipo_details_data){
        return ;
    }
    if(ipo_details_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_details_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_details_data->id) {
        free(ipo_details_data->id);
        ipo_details_data->id = NULL;
    }
    if (ipo_details_data->symbol) {
        free(ipo_details_data->symbol);
        ipo_details_data->symbol = NULL;
    }
    if (ipo_details_data->name) {
        free(ipo_details_data->name);
        ipo_details_data->name = NULL;
    }
    if (ipo_details_data->isin) {
        free(ipo_details_data->isin);
        ipo_details_data->isin = NULL;
    }
    if (ipo_details_data->issue_size) {
        free(ipo_details_data->issue_size);
        ipo_details_data->issue_size = NULL;
    }
    if (ipo_details_data->industry) {
        free(ipo_details_data->industry);
        ipo_details_data->industry = NULL;
    }
    if (ipo_details_data->minimum_price) {
        free(ipo_details_data->minimum_price);
        ipo_details_data->minimum_price = NULL;
    }
    if (ipo_details_data->maximum_price) {
        free(ipo_details_data->maximum_price);
        ipo_details_data->maximum_price = NULL;
    }
    if (ipo_details_data->bidding_start_date) {
        free(ipo_details_data->bidding_start_date);
        ipo_details_data->bidding_start_date = NULL;
    }
    if (ipo_details_data->bidding_end_date) {
        free(ipo_details_data->bidding_end_date);
        ipo_details_data->bidding_end_date = NULL;
    }
    if (ipo_details_data->daily_start_time) {
        free(ipo_details_data->daily_start_time);
        ipo_details_data->daily_start_time = NULL;
    }
    if (ipo_details_data->daily_end_time) {
        free(ipo_details_data->daily_end_time);
        ipo_details_data->daily_end_time = NULL;
    }
    if (ipo_details_data->face_value) {
        free(ipo_details_data->face_value);
        ipo_details_data->face_value = NULL;
    }
    if (ipo_details_data->tick_size) {
        free(ipo_details_data->tick_size);
        ipo_details_data->tick_size = NULL;
    }
    if (ipo_details_data->lot_size) {
        free(ipo_details_data->lot_size);
        ipo_details_data->lot_size = NULL;
    }
    if (ipo_details_data->minimum_quantity) {
        free(ipo_details_data->minimum_quantity);
        ipo_details_data->minimum_quantity = NULL;
    }
    if (ipo_details_data->cut_off_price) {
        free(ipo_details_data->cut_off_price);
        ipo_details_data->cut_off_price = NULL;
    }
    if (ipo_details_data->listing_price) {
        free(ipo_details_data->listing_price);
        ipo_details_data->listing_price = NULL;
    }
    if (ipo_details_data->listing_exchange) {
        free(ipo_details_data->listing_exchange);
        ipo_details_data->listing_exchange = NULL;
    }
    if (ipo_details_data->rhp_url) {
        free(ipo_details_data->rhp_url);
        ipo_details_data->rhp_url = NULL;
    }
    if (ipo_details_data->drhp_url) {
        free(ipo_details_data->drhp_url);
        ipo_details_data->drhp_url = NULL;
    }
    if (ipo_details_data->timeline) {
        ipo_timeline_free(ipo_details_data->timeline);
        ipo_details_data->timeline = NULL;
    }
    if (ipo_details_data->registrar_info) {
        ipo_registrar_info_free(ipo_details_data->registrar_info);
        ipo_details_data->registrar_info = NULL;
    }
    if (ipo_details_data->total_subscription) {
        free(ipo_details_data->total_subscription);
        ipo_details_data->total_subscription = NULL;
    }
    if (ipo_details_data->investors) {
        list_ForEach(listEntry, ipo_details_data->investors) {
            ipo_investor_type_free(listEntry->data);
        }
        list_freeList(ipo_details_data->investors);
        ipo_details_data->investors = NULL;
    }
    free(ipo_details_data);
}

cJSON *ipo_details_data_convertToJSON(ipo_details_data_t *ipo_details_data) {
    cJSON *item = cJSON_CreateObject();

    // ipo_details_data->id
    if(ipo_details_data->id) {
    if(cJSON_AddStringToObject(item, "id", ipo_details_data->id) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->symbol
    if(ipo_details_data->symbol) {
    if(cJSON_AddStringToObject(item, "symbol", ipo_details_data->symbol) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->name
    if(ipo_details_data->name) {
    if(cJSON_AddStringToObject(item, "name", ipo_details_data->name) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->status
    if(ipo_details_data->status != upstox_client_ipo_details_data_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", ipo_details_data_status_ToString(ipo_details_data->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // ipo_details_data->isin
    if(ipo_details_data->isin) {
    if(cJSON_AddStringToObject(item, "isin", ipo_details_data->isin) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->issue_type
    if(ipo_details_data->issue_type != upstox_client_ipo_details_data_ISSUETYPE_NULL) {
    if(cJSON_AddStringToObject(item, "issue_type", ipo_details_data_issue_type_ToString(ipo_details_data->issue_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // ipo_details_data->issue_size
    if(ipo_details_data->issue_size) {
    if(cJSON_AddNumberToObject(item, "issue_size", *ipo_details_data->issue_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_details_data->industry
    if(ipo_details_data->industry) {
    if(cJSON_AddStringToObject(item, "industry", ipo_details_data->industry) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->minimum_price
    if(ipo_details_data->minimum_price) {
    if(cJSON_AddNumberToObject(item, "minimum_price", *ipo_details_data->minimum_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_details_data->maximum_price
    if(ipo_details_data->maximum_price) {
    if(cJSON_AddNumberToObject(item, "maximum_price", *ipo_details_data->maximum_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_details_data->bidding_start_date
    if(ipo_details_data->bidding_start_date) {
    if(cJSON_AddStringToObject(item, "bidding_start_date", ipo_details_data->bidding_start_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->bidding_end_date
    if(ipo_details_data->bidding_end_date) {
    if(cJSON_AddStringToObject(item, "bidding_end_date", ipo_details_data->bidding_end_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->daily_start_time
    if(ipo_details_data->daily_start_time) {
    if(cJSON_AddStringToObject(item, "daily_start_time", ipo_details_data->daily_start_time) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->daily_end_time
    if(ipo_details_data->daily_end_time) {
    if(cJSON_AddStringToObject(item, "daily_end_time", ipo_details_data->daily_end_time) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->face_value
    if(ipo_details_data->face_value) {
    if(cJSON_AddNumberToObject(item, "face_value", *ipo_details_data->face_value) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_details_data->tick_size
    if(ipo_details_data->tick_size) {
    if(cJSON_AddNumberToObject(item, "tick_size", *ipo_details_data->tick_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_details_data->lot_size
    if(ipo_details_data->lot_size) {
    if(cJSON_AddNumberToObject(item, "lot_size", *ipo_details_data->lot_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_details_data->minimum_quantity
    if(ipo_details_data->minimum_quantity) {
    if(cJSON_AddNumberToObject(item, "minimum_quantity", *ipo_details_data->minimum_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_details_data->cut_off_price
    if(ipo_details_data->cut_off_price) {
    if(cJSON_AddNumberToObject(item, "cut_off_price", *ipo_details_data->cut_off_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_details_data->listing_price
    if(ipo_details_data->listing_price) {
    if(cJSON_AddNumberToObject(item, "listing_price", *ipo_details_data->listing_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_details_data->listing_exchange
    if(ipo_details_data->listing_exchange) {
    if(cJSON_AddStringToObject(item, "listing_exchange", ipo_details_data->listing_exchange) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->rhp_url
    if(ipo_details_data->rhp_url) {
    if(cJSON_AddStringToObject(item, "rhp_url", ipo_details_data->rhp_url) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->drhp_url
    if(ipo_details_data->drhp_url) {
    if(cJSON_AddStringToObject(item, "drhp_url", ipo_details_data->drhp_url) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->timeline
    if(ipo_details_data->timeline) {
    cJSON *timeline_local_JSON = ipo_timeline_convertToJSON(ipo_details_data->timeline);
    if(timeline_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "timeline", timeline_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // ipo_details_data->registrar_info
    if(ipo_details_data->registrar_info) {
    cJSON *registrar_info_local_JSON = ipo_registrar_info_convertToJSON(ipo_details_data->registrar_info);
    if(registrar_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "registrar_info", registrar_info_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // ipo_details_data->total_subscription
    if(ipo_details_data->total_subscription) {
    if(cJSON_AddStringToObject(item, "total_subscription", ipo_details_data->total_subscription) == NULL) {
    goto fail; //String
    }
    }


    // ipo_details_data->investors
    if(ipo_details_data->investors) {
    cJSON *investors = cJSON_AddArrayToObject(item, "investors");
    if(investors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *investorsListEntry;
    if (ipo_details_data->investors) {
    list_ForEach(investorsListEntry, ipo_details_data->investors) {
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

ipo_details_data_t *ipo_details_data_parseFromJSON(cJSON *ipo_details_dataJSON){

    ipo_details_data_t *ipo_details_data_local_var = NULL;

    char *id_local_str = NULL;

    char *symbol_local_str = NULL;

    char *name_local_str = NULL;

    char *isin_local_str = NULL;

    // define the local variable for ipo_details_data->issue_size
    double *issue_size_local_var = NULL;

    char *industry_local_str = NULL;

    // define the local variable for ipo_details_data->minimum_price
    double *minimum_price_local_var = NULL;

    // define the local variable for ipo_details_data->maximum_price
    double *maximum_price_local_var = NULL;

    char *bidding_start_date_local_str = NULL;

    char *bidding_end_date_local_str = NULL;

    char *daily_start_time_local_str = NULL;

    char *daily_end_time_local_str = NULL;

    // define the local variable for ipo_details_data->face_value
    double *face_value_local_var = NULL;

    // define the local variable for ipo_details_data->tick_size
    double *tick_size_local_var = NULL;

    // define the local variable for ipo_details_data->lot_size
    int *lot_size_local_var = NULL;

    // define the local variable for ipo_details_data->minimum_quantity
    int *minimum_quantity_local_var = NULL;

    // define the local variable for ipo_details_data->cut_off_price
    double *cut_off_price_local_var = NULL;

    // define the local variable for ipo_details_data->listing_price
    double *listing_price_local_var = NULL;

    char *listing_exchange_local_str = NULL;

    char *rhp_url_local_str = NULL;

    char *drhp_url_local_str = NULL;

    // define the local variable for ipo_details_data->timeline
    ipo_timeline_t *timeline_local_nonprim = NULL;

    // define the local variable for ipo_details_data->registrar_info
    ipo_registrar_info_t *registrar_info_local_nonprim = NULL;

    char *total_subscription_local_str = NULL;

    // define the local list for ipo_details_data->investors
    list_t *investorsList = NULL;

    // ipo_details_data->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // ipo_details_data->symbol
    cJSON *symbol = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "symbol");
    if (cJSON_IsNull(symbol)) {
        symbol = NULL;
    }
    if (symbol) { 
    if(!cJSON_IsString(symbol) && !cJSON_IsNull(symbol))
    {
    goto end; //String
    }
    }

    // ipo_details_data->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // ipo_details_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_ipo_details_data_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = ipo_details_data_status_FromString(status->valuestring);
    }

    // ipo_details_data->isin
    cJSON *isin = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "isin");
    if (cJSON_IsNull(isin)) {
        isin = NULL;
    }
    if (isin) { 
    if(!cJSON_IsString(isin) && !cJSON_IsNull(isin))
    {
    goto end; //String
    }
    }

    // ipo_details_data->issue_type
    cJSON *issue_type = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "issue_type");
    if (cJSON_IsNull(issue_type)) {
        issue_type = NULL;
    }
    upstox_client_ipo_details_data_ISSUETYPE_e issue_typeVariable;
    if (issue_type) { 
    if(!cJSON_IsString(issue_type))
    {
    goto end; //Enum
    }
    issue_typeVariable = ipo_details_data_issue_type_FromString(issue_type->valuestring);
    }

    // ipo_details_data->issue_size
    cJSON *issue_size = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "issue_size");
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

    // ipo_details_data->industry
    cJSON *industry = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "industry");
    if (cJSON_IsNull(industry)) {
        industry = NULL;
    }
    if (industry) { 
    if(!cJSON_IsString(industry) && !cJSON_IsNull(industry))
    {
    goto end; //String
    }
    }

    // ipo_details_data->minimum_price
    cJSON *minimum_price = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "minimum_price");
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

    // ipo_details_data->maximum_price
    cJSON *maximum_price = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "maximum_price");
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

    // ipo_details_data->bidding_start_date
    cJSON *bidding_start_date = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "bidding_start_date");
    if (cJSON_IsNull(bidding_start_date)) {
        bidding_start_date = NULL;
    }
    if (bidding_start_date) { 
    if(!cJSON_IsString(bidding_start_date) && !cJSON_IsNull(bidding_start_date))
    {
    goto end; //String
    }
    }

    // ipo_details_data->bidding_end_date
    cJSON *bidding_end_date = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "bidding_end_date");
    if (cJSON_IsNull(bidding_end_date)) {
        bidding_end_date = NULL;
    }
    if (bidding_end_date) { 
    if(!cJSON_IsString(bidding_end_date) && !cJSON_IsNull(bidding_end_date))
    {
    goto end; //String
    }
    }

    // ipo_details_data->daily_start_time
    cJSON *daily_start_time = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "daily_start_time");
    if (cJSON_IsNull(daily_start_time)) {
        daily_start_time = NULL;
    }
    if (daily_start_time) { 
    if(!cJSON_IsString(daily_start_time) && !cJSON_IsNull(daily_start_time))
    {
    goto end; //String
    }
    }

    // ipo_details_data->daily_end_time
    cJSON *daily_end_time = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "daily_end_time");
    if (cJSON_IsNull(daily_end_time)) {
        daily_end_time = NULL;
    }
    if (daily_end_time) { 
    if(!cJSON_IsString(daily_end_time) && !cJSON_IsNull(daily_end_time))
    {
    goto end; //String
    }
    }

    // ipo_details_data->face_value
    cJSON *face_value = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "face_value");
    if (cJSON_IsNull(face_value)) {
        face_value = NULL;
    }
    if (face_value) { 
    if(!cJSON_IsNumber(face_value))
    {
    goto end; //Numeric
    }
    face_value_local_var = malloc(sizeof(double));
    if(!face_value_local_var)
    {
        goto end;
    }
    *face_value_local_var = face_value->valuedouble;
    }

    // ipo_details_data->tick_size
    cJSON *tick_size = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "tick_size");
    if (cJSON_IsNull(tick_size)) {
        tick_size = NULL;
    }
    if (tick_size) { 
    if(!cJSON_IsNumber(tick_size))
    {
    goto end; //Numeric
    }
    tick_size_local_var = malloc(sizeof(double));
    if(!tick_size_local_var)
    {
        goto end;
    }
    *tick_size_local_var = tick_size->valuedouble;
    }

    // ipo_details_data->lot_size
    cJSON *lot_size = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "lot_size");
    if (cJSON_IsNull(lot_size)) {
        lot_size = NULL;
    }
    if (lot_size) { 
    if(!cJSON_IsNumber(lot_size))
    {
    goto end; //Numeric
    }
    lot_size_local_var = malloc(sizeof(int));
    if(!lot_size_local_var)
    {
        goto end;
    }
    *lot_size_local_var = lot_size->valuedouble;
    }

    // ipo_details_data->minimum_quantity
    cJSON *minimum_quantity = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "minimum_quantity");
    if (cJSON_IsNull(minimum_quantity)) {
        minimum_quantity = NULL;
    }
    if (minimum_quantity) { 
    if(!cJSON_IsNumber(minimum_quantity))
    {
    goto end; //Numeric
    }
    minimum_quantity_local_var = malloc(sizeof(int));
    if(!minimum_quantity_local_var)
    {
        goto end;
    }
    *minimum_quantity_local_var = minimum_quantity->valuedouble;
    }

    // ipo_details_data->cut_off_price
    cJSON *cut_off_price = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "cut_off_price");
    if (cJSON_IsNull(cut_off_price)) {
        cut_off_price = NULL;
    }
    if (cut_off_price) { 
    if(!cJSON_IsNumber(cut_off_price))
    {
    goto end; //Numeric
    }
    cut_off_price_local_var = malloc(sizeof(double));
    if(!cut_off_price_local_var)
    {
        goto end;
    }
    *cut_off_price_local_var = cut_off_price->valuedouble;
    }

    // ipo_details_data->listing_price
    cJSON *listing_price = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "listing_price");
    if (cJSON_IsNull(listing_price)) {
        listing_price = NULL;
    }
    if (listing_price) { 
    if(!cJSON_IsNumber(listing_price))
    {
    goto end; //Numeric
    }
    listing_price_local_var = malloc(sizeof(double));
    if(!listing_price_local_var)
    {
        goto end;
    }
    *listing_price_local_var = listing_price->valuedouble;
    }

    // ipo_details_data->listing_exchange
    cJSON *listing_exchange = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "listing_exchange");
    if (cJSON_IsNull(listing_exchange)) {
        listing_exchange = NULL;
    }
    if (listing_exchange) { 
    if(!cJSON_IsString(listing_exchange) && !cJSON_IsNull(listing_exchange))
    {
    goto end; //String
    }
    }

    // ipo_details_data->rhp_url
    cJSON *rhp_url = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "rhp_url");
    if (cJSON_IsNull(rhp_url)) {
        rhp_url = NULL;
    }
    if (rhp_url) { 
    if(!cJSON_IsString(rhp_url) && !cJSON_IsNull(rhp_url))
    {
    goto end; //String
    }
    }

    // ipo_details_data->drhp_url
    cJSON *drhp_url = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "drhp_url");
    if (cJSON_IsNull(drhp_url)) {
        drhp_url = NULL;
    }
    if (drhp_url) { 
    if(!cJSON_IsString(drhp_url) && !cJSON_IsNull(drhp_url))
    {
    goto end; //String
    }
    }

    // ipo_details_data->timeline
    cJSON *timeline = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "timeline");
    if (cJSON_IsNull(timeline)) {
        timeline = NULL;
    }
    if (timeline) { 
    timeline_local_nonprim = ipo_timeline_parseFromJSON(timeline); //nonprimitive
    }

    // ipo_details_data->registrar_info
    cJSON *registrar_info = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "registrar_info");
    if (cJSON_IsNull(registrar_info)) {
        registrar_info = NULL;
    }
    if (registrar_info) { 
    registrar_info_local_nonprim = ipo_registrar_info_parseFromJSON(registrar_info); //nonprimitive
    }

    // ipo_details_data->total_subscription
    cJSON *total_subscription = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "total_subscription");
    if (cJSON_IsNull(total_subscription)) {
        total_subscription = NULL;
    }
    if (total_subscription) { 
    if(!cJSON_IsString(total_subscription) && !cJSON_IsNull(total_subscription))
    {
    goto end; //String
    }
    }

    // ipo_details_data->investors
    cJSON *investors = cJSON_GetObjectItemCaseSensitive(ipo_details_dataJSON, "investors");
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
    if (daily_start_time && !cJSON_IsNull(daily_start_time)) daily_start_time_local_str = strdup(daily_start_time->valuestring);
    if (daily_end_time && !cJSON_IsNull(daily_end_time)) daily_end_time_local_str = strdup(daily_end_time->valuestring);
    if (listing_exchange && !cJSON_IsNull(listing_exchange)) listing_exchange_local_str = strdup(listing_exchange->valuestring);
    if (rhp_url && !cJSON_IsNull(rhp_url)) rhp_url_local_str = strdup(rhp_url->valuestring);
    if (drhp_url && !cJSON_IsNull(drhp_url)) drhp_url_local_str = strdup(drhp_url->valuestring);
    if (total_subscription && !cJSON_IsNull(total_subscription)) total_subscription_local_str = strdup(total_subscription->valuestring);

    ipo_details_data_local_var = ipo_details_data_create_internal (
        id_local_str,
        symbol_local_str,
        name_local_str,
        status ? statusVariable : upstox_client_ipo_details_data_STATUS_NULL,
        isin_local_str,
        issue_type ? issue_typeVariable : upstox_client_ipo_details_data_ISSUETYPE_NULL,
        issue_size_local_var,
        industry_local_str,
        minimum_price_local_var,
        maximum_price_local_var,
        bidding_start_date_local_str,
        bidding_end_date_local_str,
        daily_start_time_local_str,
        daily_end_time_local_str,
        face_value_local_var,
        tick_size_local_var,
        lot_size_local_var,
        minimum_quantity_local_var,
        cut_off_price_local_var,
        listing_price_local_var,
        listing_exchange_local_str,
        rhp_url_local_str,
        drhp_url_local_str,
        timeline ? timeline_local_nonprim : NULL,
        registrar_info ? registrar_info_local_nonprim : NULL,
        total_subscription_local_str,
        investors ? investorsList : NULL
        );

    if (!ipo_details_data_local_var) {
        goto end;
    }

    return ipo_details_data_local_var;
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
    if (daily_start_time_local_str) {
        free(daily_start_time_local_str);
        daily_start_time_local_str = NULL;
    }
    if (daily_end_time_local_str) {
        free(daily_end_time_local_str);
        daily_end_time_local_str = NULL;
    }
    if (face_value_local_var) {
        free(face_value_local_var);
        face_value_local_var = NULL;
    }
    if (tick_size_local_var) {
        free(tick_size_local_var);
        tick_size_local_var = NULL;
    }
    if (lot_size_local_var) {
        free(lot_size_local_var);
        lot_size_local_var = NULL;
    }
    if (minimum_quantity_local_var) {
        free(minimum_quantity_local_var);
        minimum_quantity_local_var = NULL;
    }
    if (cut_off_price_local_var) {
        free(cut_off_price_local_var);
        cut_off_price_local_var = NULL;
    }
    if (listing_price_local_var) {
        free(listing_price_local_var);
        listing_price_local_var = NULL;
    }
    if (listing_exchange_local_str) {
        free(listing_exchange_local_str);
        listing_exchange_local_str = NULL;
    }
    if (rhp_url_local_str) {
        free(rhp_url_local_str);
        rhp_url_local_str = NULL;
    }
    if (drhp_url_local_str) {
        free(drhp_url_local_str);
        drhp_url_local_str = NULL;
    }
    if (timeline_local_nonprim) {
        ipo_timeline_free(timeline_local_nonprim);
        timeline_local_nonprim = NULL;
    }
    if (registrar_info_local_nonprim) {
        ipo_registrar_info_free(registrar_info_local_nonprim);
        registrar_info_local_nonprim = NULL;
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
