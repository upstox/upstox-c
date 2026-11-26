#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "competitor_data.h"



static competitor_data_t *competitor_data_create_internal(
    char *company_profile,
    char *sector,
    sector_market_cap_amount_t *sector_market_cap_inr,
    sector_market_cap_amount_t *sector_market_cap_usd,
    char *instrument_key
    ) {
    competitor_data_t *competitor_data_local_var = malloc(sizeof(competitor_data_t));
    if (!competitor_data_local_var) {
        return NULL;
    }
    memset(competitor_data_local_var, 0, sizeof(competitor_data_t));
    competitor_data_local_var->_library_owned = 1;
    competitor_data_local_var->company_profile = company_profile;
    competitor_data_local_var->sector = sector;
    competitor_data_local_var->sector_market_cap_inr = sector_market_cap_inr;
    competitor_data_local_var->sector_market_cap_usd = sector_market_cap_usd;
    competitor_data_local_var->instrument_key = instrument_key;
    return competitor_data_local_var;
}

competitor_data_t *competitor_data_create(
    char *company_profile,
    char *sector,
    sector_market_cap_amount_t *sector_market_cap_inr,
    sector_market_cap_amount_t *sector_market_cap_usd,
    char *instrument_key
    ) {
    competitor_data_t *result = competitor_data_create_internal (
        company_profile,
        sector,
        sector_market_cap_inr,
        sector_market_cap_usd,
        instrument_key
        );
    if (!result) {
    }
    return result;
}

void competitor_data_free(competitor_data_t *competitor_data) {
    if(NULL == competitor_data){
        return ;
    }
    if(competitor_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "competitor_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (competitor_data->company_profile) {
        free(competitor_data->company_profile);
        competitor_data->company_profile = NULL;
    }
    if (competitor_data->sector) {
        free(competitor_data->sector);
        competitor_data->sector = NULL;
    }
    if (competitor_data->sector_market_cap_inr) {
        sector_market_cap_amount_free(competitor_data->sector_market_cap_inr);
        competitor_data->sector_market_cap_inr = NULL;
    }
    if (competitor_data->sector_market_cap_usd) {
        sector_market_cap_amount_free(competitor_data->sector_market_cap_usd);
        competitor_data->sector_market_cap_usd = NULL;
    }
    if (competitor_data->instrument_key) {
        free(competitor_data->instrument_key);
        competitor_data->instrument_key = NULL;
    }
    free(competitor_data);
}

cJSON *competitor_data_convertToJSON(competitor_data_t *competitor_data) {
    cJSON *item = cJSON_CreateObject();

    // competitor_data->company_profile
    if(competitor_data->company_profile) {
    if(cJSON_AddStringToObject(item, "company_profile", competitor_data->company_profile) == NULL) {
    goto fail; //String
    }
    }


    // competitor_data->sector
    if(competitor_data->sector) {
    if(cJSON_AddStringToObject(item, "sector", competitor_data->sector) == NULL) {
    goto fail; //String
    }
    }


    // competitor_data->sector_market_cap_inr
    if(competitor_data->sector_market_cap_inr) {
    cJSON *sector_market_cap_inr_local_JSON = sector_market_cap_amount_convertToJSON(competitor_data->sector_market_cap_inr);
    if(sector_market_cap_inr_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sector_market_cap_inr", sector_market_cap_inr_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // competitor_data->sector_market_cap_usd
    if(competitor_data->sector_market_cap_usd) {
    cJSON *sector_market_cap_usd_local_JSON = sector_market_cap_amount_convertToJSON(competitor_data->sector_market_cap_usd);
    if(sector_market_cap_usd_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sector_market_cap_usd", sector_market_cap_usd_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // competitor_data->instrument_key
    if(competitor_data->instrument_key) {
    if(cJSON_AddStringToObject(item, "instrument_key", competitor_data->instrument_key) == NULL) {
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

competitor_data_t *competitor_data_parseFromJSON(cJSON *competitor_dataJSON){

    competitor_data_t *competitor_data_local_var = NULL;

    char *company_profile_local_str = NULL;

    char *sector_local_str = NULL;

    // define the local variable for competitor_data->sector_market_cap_inr
    sector_market_cap_amount_t *sector_market_cap_inr_local_nonprim = NULL;

    // define the local variable for competitor_data->sector_market_cap_usd
    sector_market_cap_amount_t *sector_market_cap_usd_local_nonprim = NULL;

    char *instrument_key_local_str = NULL;

    // competitor_data->company_profile
    cJSON *company_profile = cJSON_GetObjectItemCaseSensitive(competitor_dataJSON, "company_profile");
    if (cJSON_IsNull(company_profile)) {
        company_profile = NULL;
    }
    if (company_profile) { 
    if(!cJSON_IsString(company_profile) && !cJSON_IsNull(company_profile))
    {
    goto end; //String
    }
    }

    // competitor_data->sector
    cJSON *sector = cJSON_GetObjectItemCaseSensitive(competitor_dataJSON, "sector");
    if (cJSON_IsNull(sector)) {
        sector = NULL;
    }
    if (sector) { 
    if(!cJSON_IsString(sector) && !cJSON_IsNull(sector))
    {
    goto end; //String
    }
    }

    // competitor_data->sector_market_cap_inr
    cJSON *sector_market_cap_inr = cJSON_GetObjectItemCaseSensitive(competitor_dataJSON, "sector_market_cap_inr");
    if (cJSON_IsNull(sector_market_cap_inr)) {
        sector_market_cap_inr = NULL;
    }
    if (sector_market_cap_inr) { 
    sector_market_cap_inr_local_nonprim = sector_market_cap_amount_parseFromJSON(sector_market_cap_inr); //nonprimitive
    }

    // competitor_data->sector_market_cap_usd
    cJSON *sector_market_cap_usd = cJSON_GetObjectItemCaseSensitive(competitor_dataJSON, "sector_market_cap_usd");
    if (cJSON_IsNull(sector_market_cap_usd)) {
        sector_market_cap_usd = NULL;
    }
    if (sector_market_cap_usd) { 
    sector_market_cap_usd_local_nonprim = sector_market_cap_amount_parseFromJSON(sector_market_cap_usd); //nonprimitive
    }

    // competitor_data->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(competitor_dataJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (instrument_key) { 
    if(!cJSON_IsString(instrument_key) && !cJSON_IsNull(instrument_key))
    {
    goto end; //String
    }
    }


    if (company_profile && !cJSON_IsNull(company_profile)) company_profile_local_str = strdup(company_profile->valuestring);
    if (sector && !cJSON_IsNull(sector)) sector_local_str = strdup(sector->valuestring);
    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);

    competitor_data_local_var = competitor_data_create_internal (
        company_profile_local_str,
        sector_local_str,
        sector_market_cap_inr ? sector_market_cap_inr_local_nonprim : NULL,
        sector_market_cap_usd ? sector_market_cap_usd_local_nonprim : NULL,
        instrument_key_local_str
        );

    if (!competitor_data_local_var) {
        goto end;
    }

    return competitor_data_local_var;
end:
    if (company_profile_local_str) {
        free(company_profile_local_str);
        company_profile_local_str = NULL;
    }
    if (sector_local_str) {
        free(sector_local_str);
        sector_local_str = NULL;
    }
    if (sector_market_cap_inr_local_nonprim) {
        sector_market_cap_amount_free(sector_market_cap_inr_local_nonprim);
        sector_market_cap_inr_local_nonprim = NULL;
    }
    if (sector_market_cap_usd_local_nonprim) {
        sector_market_cap_amount_free(sector_market_cap_usd_local_nonprim);
        sector_market_cap_usd_local_nonprim = NULL;
    }
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    return NULL;

}
