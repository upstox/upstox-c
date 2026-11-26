#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_order_data.h"


char* ipo_order_data_issue_type_ToString(upstox_client_ipo_order_data_ISSUETYPE_e issue_type) {
    char* issue_typeArray[] =  { "NULL", "regular", "sme" };
    return issue_typeArray[issue_type];
}

upstox_client_ipo_order_data_ISSUETYPE_e ipo_order_data_issue_type_FromString(char* issue_type){
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

static ipo_order_data_t *ipo_order_data_create_internal(
    char *id,
    char *symbol,
    char *exchange,
    char *request_id,
    char *order_id,
    char *status,
    char *order_status,
    char *payment_status,
    char *category,
    upstox_client_ipo_order_data_ISSUETYPE_e issue_type,
    char *reason,
    char *upi,
    char *upi_amount_blocked,
    char *nse_submitted_date,
    char *bse_submitted_date,
    char *mandate_approved_date,
    char *rejection_date,
    char *mandate_rejection_date,
    char *cancel_requested_date,
    char *cancel_accepted_date,
    int *units_allotted,
    list_t *bids,
    char *created_at,
    char *last_updated_at
    ) {
    ipo_order_data_t *ipo_order_data_local_var = malloc(sizeof(ipo_order_data_t));
    if (!ipo_order_data_local_var) {
        return NULL;
    }
    memset(ipo_order_data_local_var, 0, sizeof(ipo_order_data_t));
    ipo_order_data_local_var->_library_owned = 1;
    ipo_order_data_local_var->id = id;
    ipo_order_data_local_var->symbol = symbol;
    ipo_order_data_local_var->exchange = exchange;
    ipo_order_data_local_var->request_id = request_id;
    ipo_order_data_local_var->order_id = order_id;
    ipo_order_data_local_var->status = status;
    ipo_order_data_local_var->order_status = order_status;
    ipo_order_data_local_var->payment_status = payment_status;
    ipo_order_data_local_var->category = category;
    ipo_order_data_local_var->issue_type = issue_type;
    ipo_order_data_local_var->reason = reason;
    ipo_order_data_local_var->upi = upi;
    ipo_order_data_local_var->upi_amount_blocked = upi_amount_blocked;
    ipo_order_data_local_var->nse_submitted_date = nse_submitted_date;
    ipo_order_data_local_var->bse_submitted_date = bse_submitted_date;
    ipo_order_data_local_var->mandate_approved_date = mandate_approved_date;
    ipo_order_data_local_var->rejection_date = rejection_date;
    ipo_order_data_local_var->mandate_rejection_date = mandate_rejection_date;
    ipo_order_data_local_var->cancel_requested_date = cancel_requested_date;
    ipo_order_data_local_var->cancel_accepted_date = cancel_accepted_date;
    ipo_order_data_local_var->units_allotted = units_allotted;
    ipo_order_data_local_var->bids = bids;
    ipo_order_data_local_var->created_at = created_at;
    ipo_order_data_local_var->last_updated_at = last_updated_at;
    return ipo_order_data_local_var;
}

ipo_order_data_t *ipo_order_data_create(
    char *id,
    char *symbol,
    char *exchange,
    char *request_id,
    char *order_id,
    char *status,
    char *order_status,
    char *payment_status,
    char *category,
    upstox_client_ipo_order_data_ISSUETYPE_e issue_type,
    char *reason,
    char *upi,
    char *upi_amount_blocked,
    char *nse_submitted_date,
    char *bse_submitted_date,
    char *mandate_approved_date,
    char *rejection_date,
    char *mandate_rejection_date,
    char *cancel_requested_date,
    char *cancel_accepted_date,
    int *units_allotted,
    list_t *bids,
    char *created_at,
    char *last_updated_at
    ) {
    int *units_allotted_copy = NULL;
    if (units_allotted) {
        units_allotted_copy = malloc(sizeof(int));
        if (units_allotted_copy) *units_allotted_copy = *units_allotted;
    }
    ipo_order_data_t *result = ipo_order_data_create_internal (
        id,
        symbol,
        exchange,
        request_id,
        order_id,
        status,
        order_status,
        payment_status,
        category,
        issue_type,
        reason,
        upi,
        upi_amount_blocked,
        nse_submitted_date,
        bse_submitted_date,
        mandate_approved_date,
        rejection_date,
        mandate_rejection_date,
        cancel_requested_date,
        cancel_accepted_date,
        units_allotted_copy,
        bids,
        created_at,
        last_updated_at
        );
    if (!result) {
        free(units_allotted_copy);
    }
    return result;
}

void ipo_order_data_free(ipo_order_data_t *ipo_order_data) {
    if(NULL == ipo_order_data){
        return ;
    }
    if(ipo_order_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_order_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_order_data->id) {
        free(ipo_order_data->id);
        ipo_order_data->id = NULL;
    }
    if (ipo_order_data->symbol) {
        free(ipo_order_data->symbol);
        ipo_order_data->symbol = NULL;
    }
    if (ipo_order_data->exchange) {
        free(ipo_order_data->exchange);
        ipo_order_data->exchange = NULL;
    }
    if (ipo_order_data->request_id) {
        free(ipo_order_data->request_id);
        ipo_order_data->request_id = NULL;
    }
    if (ipo_order_data->order_id) {
        free(ipo_order_data->order_id);
        ipo_order_data->order_id = NULL;
    }
    if (ipo_order_data->status) {
        free(ipo_order_data->status);
        ipo_order_data->status = NULL;
    }
    if (ipo_order_data->order_status) {
        free(ipo_order_data->order_status);
        ipo_order_data->order_status = NULL;
    }
    if (ipo_order_data->payment_status) {
        free(ipo_order_data->payment_status);
        ipo_order_data->payment_status = NULL;
    }
    if (ipo_order_data->category) {
        free(ipo_order_data->category);
        ipo_order_data->category = NULL;
    }
    if (ipo_order_data->reason) {
        free(ipo_order_data->reason);
        ipo_order_data->reason = NULL;
    }
    if (ipo_order_data->upi) {
        free(ipo_order_data->upi);
        ipo_order_data->upi = NULL;
    }
    if (ipo_order_data->upi_amount_blocked) {
        free(ipo_order_data->upi_amount_blocked);
        ipo_order_data->upi_amount_blocked = NULL;
    }
    if (ipo_order_data->nse_submitted_date) {
        free(ipo_order_data->nse_submitted_date);
        ipo_order_data->nse_submitted_date = NULL;
    }
    if (ipo_order_data->bse_submitted_date) {
        free(ipo_order_data->bse_submitted_date);
        ipo_order_data->bse_submitted_date = NULL;
    }
    if (ipo_order_data->mandate_approved_date) {
        free(ipo_order_data->mandate_approved_date);
        ipo_order_data->mandate_approved_date = NULL;
    }
    if (ipo_order_data->rejection_date) {
        free(ipo_order_data->rejection_date);
        ipo_order_data->rejection_date = NULL;
    }
    if (ipo_order_data->mandate_rejection_date) {
        free(ipo_order_data->mandate_rejection_date);
        ipo_order_data->mandate_rejection_date = NULL;
    }
    if (ipo_order_data->cancel_requested_date) {
        free(ipo_order_data->cancel_requested_date);
        ipo_order_data->cancel_requested_date = NULL;
    }
    if (ipo_order_data->cancel_accepted_date) {
        free(ipo_order_data->cancel_accepted_date);
        ipo_order_data->cancel_accepted_date = NULL;
    }
    if (ipo_order_data->units_allotted) {
        free(ipo_order_data->units_allotted);
        ipo_order_data->units_allotted = NULL;
    }
    if (ipo_order_data->bids) {
        list_ForEach(listEntry, ipo_order_data->bids) {
            ipo_order_bid_free(listEntry->data);
        }
        list_freeList(ipo_order_data->bids);
        ipo_order_data->bids = NULL;
    }
    if (ipo_order_data->created_at) {
        free(ipo_order_data->created_at);
        ipo_order_data->created_at = NULL;
    }
    if (ipo_order_data->last_updated_at) {
        free(ipo_order_data->last_updated_at);
        ipo_order_data->last_updated_at = NULL;
    }
    free(ipo_order_data);
}

cJSON *ipo_order_data_convertToJSON(ipo_order_data_t *ipo_order_data) {
    cJSON *item = cJSON_CreateObject();

    // ipo_order_data->id
    if(ipo_order_data->id) {
    if(cJSON_AddStringToObject(item, "id", ipo_order_data->id) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->symbol
    if(ipo_order_data->symbol) {
    if(cJSON_AddStringToObject(item, "symbol", ipo_order_data->symbol) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->exchange
    if(ipo_order_data->exchange) {
    if(cJSON_AddStringToObject(item, "exchange", ipo_order_data->exchange) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->request_id
    if(ipo_order_data->request_id) {
    if(cJSON_AddStringToObject(item, "request_id", ipo_order_data->request_id) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->order_id
    if(ipo_order_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", ipo_order_data->order_id) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->status
    if(ipo_order_data->status) {
    if(cJSON_AddStringToObject(item, "status", ipo_order_data->status) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->order_status
    if(ipo_order_data->order_status) {
    if(cJSON_AddStringToObject(item, "order_status", ipo_order_data->order_status) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->payment_status
    if(ipo_order_data->payment_status) {
    if(cJSON_AddStringToObject(item, "payment_status", ipo_order_data->payment_status) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->category
    if(ipo_order_data->category) {
    if(cJSON_AddStringToObject(item, "category", ipo_order_data->category) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->issue_type
    if(ipo_order_data->issue_type != upstox_client_ipo_order_data_ISSUETYPE_NULL) {
    if(cJSON_AddStringToObject(item, "issue_type", ipo_order_data_issue_type_ToString(ipo_order_data->issue_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // ipo_order_data->reason
    if(ipo_order_data->reason) {
    if(cJSON_AddStringToObject(item, "reason", ipo_order_data->reason) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->upi
    if(ipo_order_data->upi) {
    if(cJSON_AddStringToObject(item, "upi", ipo_order_data->upi) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->upi_amount_blocked
    if(ipo_order_data->upi_amount_blocked) {
    if(cJSON_AddStringToObject(item, "upi_amount_blocked", ipo_order_data->upi_amount_blocked) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->nse_submitted_date
    if(ipo_order_data->nse_submitted_date) {
    if(cJSON_AddStringToObject(item, "nse_submitted_date", ipo_order_data->nse_submitted_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->bse_submitted_date
    if(ipo_order_data->bse_submitted_date) {
    if(cJSON_AddStringToObject(item, "bse_submitted_date", ipo_order_data->bse_submitted_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->mandate_approved_date
    if(ipo_order_data->mandate_approved_date) {
    if(cJSON_AddStringToObject(item, "mandate_approved_date", ipo_order_data->mandate_approved_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->rejection_date
    if(ipo_order_data->rejection_date) {
    if(cJSON_AddStringToObject(item, "rejection_date", ipo_order_data->rejection_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->mandate_rejection_date
    if(ipo_order_data->mandate_rejection_date) {
    if(cJSON_AddStringToObject(item, "mandate_rejection_date", ipo_order_data->mandate_rejection_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->cancel_requested_date
    if(ipo_order_data->cancel_requested_date) {
    if(cJSON_AddStringToObject(item, "cancel_requested_date", ipo_order_data->cancel_requested_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->cancel_accepted_date
    if(ipo_order_data->cancel_accepted_date) {
    if(cJSON_AddStringToObject(item, "cancel_accepted_date", ipo_order_data->cancel_accepted_date) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->units_allotted
    if(ipo_order_data->units_allotted) {
    if(cJSON_AddNumberToObject(item, "units_allotted", *ipo_order_data->units_allotted) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_order_data->bids
    if(ipo_order_data->bids) {
    cJSON *bids = cJSON_AddArrayToObject(item, "bids");
    if(bids == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *bidsListEntry;
    if (ipo_order_data->bids) {
    list_ForEach(bidsListEntry, ipo_order_data->bids) {
    cJSON *itemLocal = ipo_order_bid_convertToJSON(bidsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(bids, itemLocal);
    }
    }
    }


    // ipo_order_data->created_at
    if(ipo_order_data->created_at) {
    if(cJSON_AddStringToObject(item, "created_at", ipo_order_data->created_at) == NULL) {
    goto fail; //String
    }
    }


    // ipo_order_data->last_updated_at
    if(ipo_order_data->last_updated_at) {
    if(cJSON_AddStringToObject(item, "last_updated_at", ipo_order_data->last_updated_at) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ipo_order_data_t *ipo_order_data_parseFromJSON(cJSON *ipo_order_dataJSON){

    ipo_order_data_t *ipo_order_data_local_var = NULL;

    char *id_local_str = NULL;

    char *symbol_local_str = NULL;

    char *exchange_local_str = NULL;

    char *request_id_local_str = NULL;

    char *order_id_local_str = NULL;

    char *status_local_str = NULL;

    char *order_status_local_str = NULL;

    char *payment_status_local_str = NULL;

    char *category_local_str = NULL;

    char *reason_local_str = NULL;

    char *upi_local_str = NULL;

    char *upi_amount_blocked_local_str = NULL;

    char *nse_submitted_date_local_str = NULL;

    char *bse_submitted_date_local_str = NULL;

    char *mandate_approved_date_local_str = NULL;

    char *rejection_date_local_str = NULL;

    char *mandate_rejection_date_local_str = NULL;

    char *cancel_requested_date_local_str = NULL;

    char *cancel_accepted_date_local_str = NULL;

    // define the local variable for ipo_order_data->units_allotted
    int *units_allotted_local_var = NULL;

    // define the local list for ipo_order_data->bids
    list_t *bidsList = NULL;

    char *created_at_local_str = NULL;

    char *last_updated_at_local_str = NULL;

    // ipo_order_data->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // ipo_order_data->symbol
    cJSON *symbol = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "symbol");
    if (cJSON_IsNull(symbol)) {
        symbol = NULL;
    }
    if (symbol) { 
    if(!cJSON_IsString(symbol) && !cJSON_IsNull(symbol))
    {
    goto end; //String
    }
    }

    // ipo_order_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    if (exchange) { 
    if(!cJSON_IsString(exchange) && !cJSON_IsNull(exchange))
    {
    goto end; //String
    }
    }

    // ipo_order_data->request_id
    cJSON *request_id = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "request_id");
    if (cJSON_IsNull(request_id)) {
        request_id = NULL;
    }
    if (request_id) { 
    if(!cJSON_IsString(request_id) && !cJSON_IsNull(request_id))
    {
    goto end; //String
    }
    }

    // ipo_order_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "order_id");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (order_id) { 
    if(!cJSON_IsString(order_id) && !cJSON_IsNull(order_id))
    {
    goto end; //String
    }
    }

    // ipo_order_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // ipo_order_data->order_status
    cJSON *order_status = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "order_status");
    if (cJSON_IsNull(order_status)) {
        order_status = NULL;
    }
    if (order_status) { 
    if(!cJSON_IsString(order_status) && !cJSON_IsNull(order_status))
    {
    goto end; //String
    }
    }

    // ipo_order_data->payment_status
    cJSON *payment_status = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "payment_status");
    if (cJSON_IsNull(payment_status)) {
        payment_status = NULL;
    }
    if (payment_status) { 
    if(!cJSON_IsString(payment_status) && !cJSON_IsNull(payment_status))
    {
    goto end; //String
    }
    }

    // ipo_order_data->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "category");
    if (cJSON_IsNull(category)) {
        category = NULL;
    }
    if (category) { 
    if(!cJSON_IsString(category) && !cJSON_IsNull(category))
    {
    goto end; //String
    }
    }

    // ipo_order_data->issue_type
    cJSON *issue_type = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "issue_type");
    if (cJSON_IsNull(issue_type)) {
        issue_type = NULL;
    }
    upstox_client_ipo_order_data_ISSUETYPE_e issue_typeVariable;
    if (issue_type) { 
    if(!cJSON_IsString(issue_type))
    {
    goto end; //Enum
    }
    issue_typeVariable = ipo_order_data_issue_type_FromString(issue_type->valuestring);
    }

    // ipo_order_data->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // ipo_order_data->upi
    cJSON *upi = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "upi");
    if (cJSON_IsNull(upi)) {
        upi = NULL;
    }
    if (upi) { 
    if(!cJSON_IsString(upi) && !cJSON_IsNull(upi))
    {
    goto end; //String
    }
    }

    // ipo_order_data->upi_amount_blocked
    cJSON *upi_amount_blocked = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "upi_amount_blocked");
    if (cJSON_IsNull(upi_amount_blocked)) {
        upi_amount_blocked = NULL;
    }
    if (upi_amount_blocked) { 
    if(!cJSON_IsString(upi_amount_blocked) && !cJSON_IsNull(upi_amount_blocked))
    {
    goto end; //String
    }
    }

    // ipo_order_data->nse_submitted_date
    cJSON *nse_submitted_date = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "nse_submitted_date");
    if (cJSON_IsNull(nse_submitted_date)) {
        nse_submitted_date = NULL;
    }
    if (nse_submitted_date) { 
    if(!cJSON_IsString(nse_submitted_date) && !cJSON_IsNull(nse_submitted_date))
    {
    goto end; //String
    }
    }

    // ipo_order_data->bse_submitted_date
    cJSON *bse_submitted_date = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "bse_submitted_date");
    if (cJSON_IsNull(bse_submitted_date)) {
        bse_submitted_date = NULL;
    }
    if (bse_submitted_date) { 
    if(!cJSON_IsString(bse_submitted_date) && !cJSON_IsNull(bse_submitted_date))
    {
    goto end; //String
    }
    }

    // ipo_order_data->mandate_approved_date
    cJSON *mandate_approved_date = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "mandate_approved_date");
    if (cJSON_IsNull(mandate_approved_date)) {
        mandate_approved_date = NULL;
    }
    if (mandate_approved_date) { 
    if(!cJSON_IsString(mandate_approved_date) && !cJSON_IsNull(mandate_approved_date))
    {
    goto end; //String
    }
    }

    // ipo_order_data->rejection_date
    cJSON *rejection_date = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "rejection_date");
    if (cJSON_IsNull(rejection_date)) {
        rejection_date = NULL;
    }
    if (rejection_date) { 
    if(!cJSON_IsString(rejection_date) && !cJSON_IsNull(rejection_date))
    {
    goto end; //String
    }
    }

    // ipo_order_data->mandate_rejection_date
    cJSON *mandate_rejection_date = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "mandate_rejection_date");
    if (cJSON_IsNull(mandate_rejection_date)) {
        mandate_rejection_date = NULL;
    }
    if (mandate_rejection_date) { 
    if(!cJSON_IsString(mandate_rejection_date) && !cJSON_IsNull(mandate_rejection_date))
    {
    goto end; //String
    }
    }

    // ipo_order_data->cancel_requested_date
    cJSON *cancel_requested_date = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "cancel_requested_date");
    if (cJSON_IsNull(cancel_requested_date)) {
        cancel_requested_date = NULL;
    }
    if (cancel_requested_date) { 
    if(!cJSON_IsString(cancel_requested_date) && !cJSON_IsNull(cancel_requested_date))
    {
    goto end; //String
    }
    }

    // ipo_order_data->cancel_accepted_date
    cJSON *cancel_accepted_date = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "cancel_accepted_date");
    if (cJSON_IsNull(cancel_accepted_date)) {
        cancel_accepted_date = NULL;
    }
    if (cancel_accepted_date) { 
    if(!cJSON_IsString(cancel_accepted_date) && !cJSON_IsNull(cancel_accepted_date))
    {
    goto end; //String
    }
    }

    // ipo_order_data->units_allotted
    cJSON *units_allotted = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "units_allotted");
    if (cJSON_IsNull(units_allotted)) {
        units_allotted = NULL;
    }
    if (units_allotted) { 
    if(!cJSON_IsNumber(units_allotted))
    {
    goto end; //Numeric
    }
    units_allotted_local_var = malloc(sizeof(int));
    if(!units_allotted_local_var)
    {
        goto end;
    }
    *units_allotted_local_var = units_allotted->valuedouble;
    }

    // ipo_order_data->bids
    cJSON *bids = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "bids");
    if (cJSON_IsNull(bids)) {
        bids = NULL;
    }
    if (bids) { 
    cJSON *bids_local_nonprimitive = NULL;
    if(!cJSON_IsArray(bids)){
        goto end; //nonprimitive container
    }

    bidsList = list_createList();

    cJSON_ArrayForEach(bids_local_nonprimitive,bids )
    {
        if(!cJSON_IsObject(bids_local_nonprimitive)){
            goto end;
        }
        ipo_order_bid_t *bidsItem = ipo_order_bid_parseFromJSON(bids_local_nonprimitive);

        list_addElement(bidsList, bidsItem);
    }
    }

    // ipo_order_data->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //String
    }
    }

    // ipo_order_data->last_updated_at
    cJSON *last_updated_at = cJSON_GetObjectItemCaseSensitive(ipo_order_dataJSON, "last_updated_at");
    if (cJSON_IsNull(last_updated_at)) {
        last_updated_at = NULL;
    }
    if (last_updated_at) { 
    if(!cJSON_IsString(last_updated_at) && !cJSON_IsNull(last_updated_at))
    {
    goto end; //String
    }
    }


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (symbol && !cJSON_IsNull(symbol)) symbol_local_str = strdup(symbol->valuestring);
    if (exchange && !cJSON_IsNull(exchange)) exchange_local_str = strdup(exchange->valuestring);
    if (request_id && !cJSON_IsNull(request_id)) request_id_local_str = strdup(request_id->valuestring);
    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (order_status && !cJSON_IsNull(order_status)) order_status_local_str = strdup(order_status->valuestring);
    if (payment_status && !cJSON_IsNull(payment_status)) payment_status_local_str = strdup(payment_status->valuestring);
    if (category && !cJSON_IsNull(category)) category_local_str = strdup(category->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);
    if (upi && !cJSON_IsNull(upi)) upi_local_str = strdup(upi->valuestring);
    if (upi_amount_blocked && !cJSON_IsNull(upi_amount_blocked)) upi_amount_blocked_local_str = strdup(upi_amount_blocked->valuestring);
    if (nse_submitted_date && !cJSON_IsNull(nse_submitted_date)) nse_submitted_date_local_str = strdup(nse_submitted_date->valuestring);
    if (bse_submitted_date && !cJSON_IsNull(bse_submitted_date)) bse_submitted_date_local_str = strdup(bse_submitted_date->valuestring);
    if (mandate_approved_date && !cJSON_IsNull(mandate_approved_date)) mandate_approved_date_local_str = strdup(mandate_approved_date->valuestring);
    if (rejection_date && !cJSON_IsNull(rejection_date)) rejection_date_local_str = strdup(rejection_date->valuestring);
    if (mandate_rejection_date && !cJSON_IsNull(mandate_rejection_date)) mandate_rejection_date_local_str = strdup(mandate_rejection_date->valuestring);
    if (cancel_requested_date && !cJSON_IsNull(cancel_requested_date)) cancel_requested_date_local_str = strdup(cancel_requested_date->valuestring);
    if (cancel_accepted_date && !cJSON_IsNull(cancel_accepted_date)) cancel_accepted_date_local_str = strdup(cancel_accepted_date->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (last_updated_at && !cJSON_IsNull(last_updated_at)) last_updated_at_local_str = strdup(last_updated_at->valuestring);

    ipo_order_data_local_var = ipo_order_data_create_internal (
        id_local_str,
        symbol_local_str,
        exchange_local_str,
        request_id_local_str,
        order_id_local_str,
        status_local_str,
        order_status_local_str,
        payment_status_local_str,
        category_local_str,
        issue_type ? issue_typeVariable : upstox_client_ipo_order_data_ISSUETYPE_NULL,
        reason_local_str,
        upi_local_str,
        upi_amount_blocked_local_str,
        nse_submitted_date_local_str,
        bse_submitted_date_local_str,
        mandate_approved_date_local_str,
        rejection_date_local_str,
        mandate_rejection_date_local_str,
        cancel_requested_date_local_str,
        cancel_accepted_date_local_str,
        units_allotted_local_var,
        bids ? bidsList : NULL,
        created_at_local_str,
        last_updated_at_local_str
        );

    if (!ipo_order_data_local_var) {
        goto end;
    }

    return ipo_order_data_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (symbol_local_str) {
        free(symbol_local_str);
        symbol_local_str = NULL;
    }
    if (exchange_local_str) {
        free(exchange_local_str);
        exchange_local_str = NULL;
    }
    if (request_id_local_str) {
        free(request_id_local_str);
        request_id_local_str = NULL;
    }
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (order_status_local_str) {
        free(order_status_local_str);
        order_status_local_str = NULL;
    }
    if (payment_status_local_str) {
        free(payment_status_local_str);
        payment_status_local_str = NULL;
    }
    if (category_local_str) {
        free(category_local_str);
        category_local_str = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    if (upi_local_str) {
        free(upi_local_str);
        upi_local_str = NULL;
    }
    if (upi_amount_blocked_local_str) {
        free(upi_amount_blocked_local_str);
        upi_amount_blocked_local_str = NULL;
    }
    if (nse_submitted_date_local_str) {
        free(nse_submitted_date_local_str);
        nse_submitted_date_local_str = NULL;
    }
    if (bse_submitted_date_local_str) {
        free(bse_submitted_date_local_str);
        bse_submitted_date_local_str = NULL;
    }
    if (mandate_approved_date_local_str) {
        free(mandate_approved_date_local_str);
        mandate_approved_date_local_str = NULL;
    }
    if (rejection_date_local_str) {
        free(rejection_date_local_str);
        rejection_date_local_str = NULL;
    }
    if (mandate_rejection_date_local_str) {
        free(mandate_rejection_date_local_str);
        mandate_rejection_date_local_str = NULL;
    }
    if (cancel_requested_date_local_str) {
        free(cancel_requested_date_local_str);
        cancel_requested_date_local_str = NULL;
    }
    if (cancel_accepted_date_local_str) {
        free(cancel_accepted_date_local_str);
        cancel_accepted_date_local_str = NULL;
    }
    if (units_allotted_local_var) {
        free(units_allotted_local_var);
        units_allotted_local_var = NULL;
    }
    if (bidsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, bidsList) {
            ipo_order_bid_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(bidsList);
        bidsList = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (last_updated_at_local_str) {
        free(last_updated_at_local_str);
        last_updated_at_local_str = NULL;
    }
    return NULL;

}
