#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "company_profile_data.h"



static company_profile_data_t *company_profile_data_create_internal(
    char *company_profile,
    char *sector,
    sector_market_cap_amount_t *sector_market_cap_inr,
    sector_market_cap_amount_t *sector_market_cap_usd
    ) {
    company_profile_data_t *company_profile_data_local_var = malloc(sizeof(company_profile_data_t));
    if (!company_profile_data_local_var) {
        return NULL;
    }
    memset(company_profile_data_local_var, 0, sizeof(company_profile_data_t));
    company_profile_data_local_var->_library_owned = 1;
    company_profile_data_local_var->company_profile = company_profile;
    company_profile_data_local_var->sector = sector;
    company_profile_data_local_var->sector_market_cap_inr = sector_market_cap_inr;
    company_profile_data_local_var->sector_market_cap_usd = sector_market_cap_usd;
    return company_profile_data_local_var;
}

company_profile_data_t *company_profile_data_create(
    char *company_profile,
    char *sector,
    sector_market_cap_amount_t *sector_market_cap_inr,
    sector_market_cap_amount_t *sector_market_cap_usd
    ) {
    company_profile_data_t *result = company_profile_data_create_internal (
        company_profile,
        sector,
        sector_market_cap_inr,
        sector_market_cap_usd
        );
    if (!result) {
    }
    return result;
}

void company_profile_data_free(company_profile_data_t *company_profile_data) {
    if(NULL == company_profile_data){
        return ;
    }
    if(company_profile_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "company_profile_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (company_profile_data->company_profile) {
        free(company_profile_data->company_profile);
        company_profile_data->company_profile = NULL;
    }
    if (company_profile_data->sector) {
        free(company_profile_data->sector);
        company_profile_data->sector = NULL;
    }
    if (company_profile_data->sector_market_cap_inr) {
        sector_market_cap_amount_free(company_profile_data->sector_market_cap_inr);
        company_profile_data->sector_market_cap_inr = NULL;
    }
    if (company_profile_data->sector_market_cap_usd) {
        sector_market_cap_amount_free(company_profile_data->sector_market_cap_usd);
        company_profile_data->sector_market_cap_usd = NULL;
    }
    free(company_profile_data);
}

cJSON *company_profile_data_convertToJSON(company_profile_data_t *company_profile_data) {
    cJSON *item = cJSON_CreateObject();

    // company_profile_data->company_profile
    if(company_profile_data->company_profile) {
    if(cJSON_AddStringToObject(item, "company_profile", company_profile_data->company_profile) == NULL) {
    goto fail; //String
    }
    }


    // company_profile_data->sector
    if(company_profile_data->sector) {
    if(cJSON_AddStringToObject(item, "sector", company_profile_data->sector) == NULL) {
    goto fail; //String
    }
    }


    // company_profile_data->sector_market_cap_inr
    if(company_profile_data->sector_market_cap_inr) {
    cJSON *sector_market_cap_inr_local_JSON = sector_market_cap_amount_convertToJSON(company_profile_data->sector_market_cap_inr);
    if(sector_market_cap_inr_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sector_market_cap_inr", sector_market_cap_inr_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // company_profile_data->sector_market_cap_usd
    if(company_profile_data->sector_market_cap_usd) {
    cJSON *sector_market_cap_usd_local_JSON = sector_market_cap_amount_convertToJSON(company_profile_data->sector_market_cap_usd);
    if(sector_market_cap_usd_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "sector_market_cap_usd", sector_market_cap_usd_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

company_profile_data_t *company_profile_data_parseFromJSON(cJSON *company_profile_dataJSON){

    company_profile_data_t *company_profile_data_local_var = NULL;

    char *company_profile_local_str = NULL;

    char *sector_local_str = NULL;

    // define the local variable for company_profile_data->sector_market_cap_inr
    sector_market_cap_amount_t *sector_market_cap_inr_local_nonprim = NULL;

    // define the local variable for company_profile_data->sector_market_cap_usd
    sector_market_cap_amount_t *sector_market_cap_usd_local_nonprim = NULL;

    // company_profile_data->company_profile
    cJSON *company_profile = cJSON_GetObjectItemCaseSensitive(company_profile_dataJSON, "company_profile");
    if (cJSON_IsNull(company_profile)) {
        company_profile = NULL;
    }
    if (company_profile) { 
    if(!cJSON_IsString(company_profile) && !cJSON_IsNull(company_profile))
    {
    goto end; //String
    }
    }

    // company_profile_data->sector
    cJSON *sector = cJSON_GetObjectItemCaseSensitive(company_profile_dataJSON, "sector");
    if (cJSON_IsNull(sector)) {
        sector = NULL;
    }
    if (sector) { 
    if(!cJSON_IsString(sector) && !cJSON_IsNull(sector))
    {
    goto end; //String
    }
    }

    // company_profile_data->sector_market_cap_inr
    cJSON *sector_market_cap_inr = cJSON_GetObjectItemCaseSensitive(company_profile_dataJSON, "sector_market_cap_inr");
    if (cJSON_IsNull(sector_market_cap_inr)) {
        sector_market_cap_inr = NULL;
    }
    if (sector_market_cap_inr) { 
    sector_market_cap_inr_local_nonprim = sector_market_cap_amount_parseFromJSON(sector_market_cap_inr); //nonprimitive
    }

    // company_profile_data->sector_market_cap_usd
    cJSON *sector_market_cap_usd = cJSON_GetObjectItemCaseSensitive(company_profile_dataJSON, "sector_market_cap_usd");
    if (cJSON_IsNull(sector_market_cap_usd)) {
        sector_market_cap_usd = NULL;
    }
    if (sector_market_cap_usd) { 
    sector_market_cap_usd_local_nonprim = sector_market_cap_amount_parseFromJSON(sector_market_cap_usd); //nonprimitive
    }


    if (company_profile && !cJSON_IsNull(company_profile)) company_profile_local_str = strdup(company_profile->valuestring);
    if (sector && !cJSON_IsNull(sector)) sector_local_str = strdup(sector->valuestring);

    company_profile_data_local_var = company_profile_data_create_internal (
        company_profile_local_str,
        sector_local_str,
        sector_market_cap_inr ? sector_market_cap_inr_local_nonprim : NULL,
        sector_market_cap_usd ? sector_market_cap_usd_local_nonprim : NULL
        );

    if (!company_profile_data_local_var) {
        goto end;
    }

    return company_profile_data_local_var;
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
    return NULL;

}
