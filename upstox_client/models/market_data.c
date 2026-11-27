#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "market_data.h"



static market_data_t *market_data_create_internal(
    double *ltp,
    long *volume,
    double *oi,
    double *close_price,
    double *bid_price,
    int *bid_qty,
    double *ask_price,
    int *ask_qty,
    double *prev_oi
    ) {
    market_data_t *market_data_local_var = malloc(sizeof(market_data_t));
    if (!market_data_local_var) {
        return NULL;
    }
    memset(market_data_local_var, 0, sizeof(market_data_t));
    market_data_local_var->_library_owned = 1;
    market_data_local_var->ltp = ltp;
    market_data_local_var->volume = volume;
    market_data_local_var->oi = oi;
    market_data_local_var->close_price = close_price;
    market_data_local_var->bid_price = bid_price;
    market_data_local_var->bid_qty = bid_qty;
    market_data_local_var->ask_price = ask_price;
    market_data_local_var->ask_qty = ask_qty;
    market_data_local_var->prev_oi = prev_oi;
    return market_data_local_var;
}

market_data_t *market_data_create(
    double *ltp,
    long *volume,
    double *oi,
    double *close_price,
    double *bid_price,
    int *bid_qty,
    double *ask_price,
    int *ask_qty,
    double *prev_oi
    ) {
    double *ltp_copy = NULL;
    if (ltp) {
        ltp_copy = malloc(sizeof(double));
        if (ltp_copy) *ltp_copy = *ltp;
    }
    long *volume_copy = NULL;
    if (volume) {
        volume_copy = malloc(sizeof(long));
        if (volume_copy) *volume_copy = *volume;
    }
    double *oi_copy = NULL;
    if (oi) {
        oi_copy = malloc(sizeof(double));
        if (oi_copy) *oi_copy = *oi;
    }
    double *close_price_copy = NULL;
    if (close_price) {
        close_price_copy = malloc(sizeof(double));
        if (close_price_copy) *close_price_copy = *close_price;
    }
    double *bid_price_copy = NULL;
    if (bid_price) {
        bid_price_copy = malloc(sizeof(double));
        if (bid_price_copy) *bid_price_copy = *bid_price;
    }
    int *bid_qty_copy = NULL;
    if (bid_qty) {
        bid_qty_copy = malloc(sizeof(int));
        if (bid_qty_copy) *bid_qty_copy = *bid_qty;
    }
    double *ask_price_copy = NULL;
    if (ask_price) {
        ask_price_copy = malloc(sizeof(double));
        if (ask_price_copy) *ask_price_copy = *ask_price;
    }
    int *ask_qty_copy = NULL;
    if (ask_qty) {
        ask_qty_copy = malloc(sizeof(int));
        if (ask_qty_copy) *ask_qty_copy = *ask_qty;
    }
    double *prev_oi_copy = NULL;
    if (prev_oi) {
        prev_oi_copy = malloc(sizeof(double));
        if (prev_oi_copy) *prev_oi_copy = *prev_oi;
    }
    market_data_t *result = market_data_create_internal (
        ltp_copy,
        volume_copy,
        oi_copy,
        close_price_copy,
        bid_price_copy,
        bid_qty_copy,
        ask_price_copy,
        ask_qty_copy,
        prev_oi_copy
        );
    if (!result) {
        free(ltp_copy);
        free(volume_copy);
        free(oi_copy);
        free(close_price_copy);
        free(bid_price_copy);
        free(bid_qty_copy);
        free(ask_price_copy);
        free(ask_qty_copy);
        free(prev_oi_copy);
    }
    return result;
}

void market_data_free(market_data_t *market_data) {
    if(NULL == market_data){
        return ;
    }
    if(market_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "market_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (market_data->ltp) {
        free(market_data->ltp);
        market_data->ltp = NULL;
    }
    if (market_data->volume) {
        free(market_data->volume);
        market_data->volume = NULL;
    }
    if (market_data->oi) {
        free(market_data->oi);
        market_data->oi = NULL;
    }
    if (market_data->close_price) {
        free(market_data->close_price);
        market_data->close_price = NULL;
    }
    if (market_data->bid_price) {
        free(market_data->bid_price);
        market_data->bid_price = NULL;
    }
    if (market_data->bid_qty) {
        free(market_data->bid_qty);
        market_data->bid_qty = NULL;
    }
    if (market_data->ask_price) {
        free(market_data->ask_price);
        market_data->ask_price = NULL;
    }
    if (market_data->ask_qty) {
        free(market_data->ask_qty);
        market_data->ask_qty = NULL;
    }
    if (market_data->prev_oi) {
        free(market_data->prev_oi);
        market_data->prev_oi = NULL;
    }
    free(market_data);
}

cJSON *market_data_convertToJSON(market_data_t *market_data) {
    cJSON *item = cJSON_CreateObject();

    // market_data->ltp
    if(market_data->ltp) {
    if(cJSON_AddNumberToObject(item, "ltp", *market_data->ltp) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_data->volume
    if(market_data->volume) {
    if(cJSON_AddNumberToObject(item, "volume", *market_data->volume) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_data->oi
    if(market_data->oi) {
    if(cJSON_AddNumberToObject(item, "oi", *market_data->oi) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_data->close_price
    if(market_data->close_price) {
    if(cJSON_AddNumberToObject(item, "close_price", *market_data->close_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_data->bid_price
    if(market_data->bid_price) {
    if(cJSON_AddNumberToObject(item, "bid_price", *market_data->bid_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_data->bid_qty
    if(market_data->bid_qty) {
    if(cJSON_AddNumberToObject(item, "bid_qty", *market_data->bid_qty) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_data->ask_price
    if(market_data->ask_price) {
    if(cJSON_AddNumberToObject(item, "ask_price", *market_data->ask_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_data->ask_qty
    if(market_data->ask_qty) {
    if(cJSON_AddNumberToObject(item, "ask_qty", *market_data->ask_qty) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_data->prev_oi
    if(market_data->prev_oi) {
    if(cJSON_AddNumberToObject(item, "prev_oi", *market_data->prev_oi) == NULL) {
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

market_data_t *market_data_parseFromJSON(cJSON *market_dataJSON){

    market_data_t *market_data_local_var = NULL;

    // define the local variable for market_data->ltp
    double *ltp_local_var = NULL;

    // define the local variable for market_data->volume
    long *volume_local_var = NULL;

    // define the local variable for market_data->oi
    double *oi_local_var = NULL;

    // define the local variable for market_data->close_price
    double *close_price_local_var = NULL;

    // define the local variable for market_data->bid_price
    double *bid_price_local_var = NULL;

    // define the local variable for market_data->bid_qty
    int *bid_qty_local_var = NULL;

    // define the local variable for market_data->ask_price
    double *ask_price_local_var = NULL;

    // define the local variable for market_data->ask_qty
    int *ask_qty_local_var = NULL;

    // define the local variable for market_data->prev_oi
    double *prev_oi_local_var = NULL;

    // market_data->ltp
    cJSON *ltp = cJSON_GetObjectItemCaseSensitive(market_dataJSON, "ltp");
    if (cJSON_IsNull(ltp)) {
        ltp = NULL;
    }
    if (ltp) { 
    if(!cJSON_IsNumber(ltp))
    {
    goto end; //Numeric
    }
    ltp_local_var = malloc(sizeof(double));
    if(!ltp_local_var)
    {
        goto end;
    }
    *ltp_local_var = ltp->valuedouble;
    }

    // market_data->volume
    cJSON *volume = cJSON_GetObjectItemCaseSensitive(market_dataJSON, "volume");
    if (cJSON_IsNull(volume)) {
        volume = NULL;
    }
    if (volume) { 
    if(!cJSON_IsNumber(volume))
    {
    goto end; //Numeric
    }
    volume_local_var = malloc(sizeof(long));
    if(!volume_local_var)
    {
        goto end;
    }
    *volume_local_var = volume->valuedouble;
    }

    // market_data->oi
    cJSON *oi = cJSON_GetObjectItemCaseSensitive(market_dataJSON, "oi");
    if (cJSON_IsNull(oi)) {
        oi = NULL;
    }
    if (oi) { 
    if(!cJSON_IsNumber(oi))
    {
    goto end; //Numeric
    }
    oi_local_var = malloc(sizeof(double));
    if(!oi_local_var)
    {
        goto end;
    }
    *oi_local_var = oi->valuedouble;
    }

    // market_data->close_price
    cJSON *close_price = cJSON_GetObjectItemCaseSensitive(market_dataJSON, "close_price");
    if (cJSON_IsNull(close_price)) {
        close_price = NULL;
    }
    if (close_price) { 
    if(!cJSON_IsNumber(close_price))
    {
    goto end; //Numeric
    }
    close_price_local_var = malloc(sizeof(double));
    if(!close_price_local_var)
    {
        goto end;
    }
    *close_price_local_var = close_price->valuedouble;
    }

    // market_data->bid_price
    cJSON *bid_price = cJSON_GetObjectItemCaseSensitive(market_dataJSON, "bid_price");
    if (cJSON_IsNull(bid_price)) {
        bid_price = NULL;
    }
    if (bid_price) { 
    if(!cJSON_IsNumber(bid_price))
    {
    goto end; //Numeric
    }
    bid_price_local_var = malloc(sizeof(double));
    if(!bid_price_local_var)
    {
        goto end;
    }
    *bid_price_local_var = bid_price->valuedouble;
    }

    // market_data->bid_qty
    cJSON *bid_qty = cJSON_GetObjectItemCaseSensitive(market_dataJSON, "bid_qty");
    if (cJSON_IsNull(bid_qty)) {
        bid_qty = NULL;
    }
    if (bid_qty) { 
    if(!cJSON_IsNumber(bid_qty))
    {
    goto end; //Numeric
    }
    bid_qty_local_var = malloc(sizeof(int));
    if(!bid_qty_local_var)
    {
        goto end;
    }
    *bid_qty_local_var = bid_qty->valuedouble;
    }

    // market_data->ask_price
    cJSON *ask_price = cJSON_GetObjectItemCaseSensitive(market_dataJSON, "ask_price");
    if (cJSON_IsNull(ask_price)) {
        ask_price = NULL;
    }
    if (ask_price) { 
    if(!cJSON_IsNumber(ask_price))
    {
    goto end; //Numeric
    }
    ask_price_local_var = malloc(sizeof(double));
    if(!ask_price_local_var)
    {
        goto end;
    }
    *ask_price_local_var = ask_price->valuedouble;
    }

    // market_data->ask_qty
    cJSON *ask_qty = cJSON_GetObjectItemCaseSensitive(market_dataJSON, "ask_qty");
    if (cJSON_IsNull(ask_qty)) {
        ask_qty = NULL;
    }
    if (ask_qty) { 
    if(!cJSON_IsNumber(ask_qty))
    {
    goto end; //Numeric
    }
    ask_qty_local_var = malloc(sizeof(int));
    if(!ask_qty_local_var)
    {
        goto end;
    }
    *ask_qty_local_var = ask_qty->valuedouble;
    }

    // market_data->prev_oi
    cJSON *prev_oi = cJSON_GetObjectItemCaseSensitive(market_dataJSON, "prev_oi");
    if (cJSON_IsNull(prev_oi)) {
        prev_oi = NULL;
    }
    if (prev_oi) { 
    if(!cJSON_IsNumber(prev_oi))
    {
    goto end; //Numeric
    }
    prev_oi_local_var = malloc(sizeof(double));
    if(!prev_oi_local_var)
    {
        goto end;
    }
    *prev_oi_local_var = prev_oi->valuedouble;
    }



    market_data_local_var = market_data_create_internal (
        ltp_local_var,
        volume_local_var,
        oi_local_var,
        close_price_local_var,
        bid_price_local_var,
        bid_qty_local_var,
        ask_price_local_var,
        ask_qty_local_var,
        prev_oi_local_var
        );

    if (!market_data_local_var) {
        goto end;
    }

    return market_data_local_var;
end:
    if (ltp_local_var) {
        free(ltp_local_var);
        ltp_local_var = NULL;
    }
    if (volume_local_var) {
        free(volume_local_var);
        volume_local_var = NULL;
    }
    if (oi_local_var) {
        free(oi_local_var);
        oi_local_var = NULL;
    }
    if (close_price_local_var) {
        free(close_price_local_var);
        close_price_local_var = NULL;
    }
    if (bid_price_local_var) {
        free(bid_price_local_var);
        bid_price_local_var = NULL;
    }
    if (bid_qty_local_var) {
        free(bid_qty_local_var);
        bid_qty_local_var = NULL;
    }
    if (ask_price_local_var) {
        free(ask_price_local_var);
        ask_price_local_var = NULL;
    }
    if (ask_qty_local_var) {
        free(ask_qty_local_var);
        ask_qty_local_var = NULL;
    }
    if (prev_oi_local_var) {
        free(prev_oi_local_var);
        prev_oi_local_var = NULL;
    }
    return NULL;

}
