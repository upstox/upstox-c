#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sector_market_cap_amount.h"



static sector_market_cap_amount_t *sector_market_cap_amount_create_internal(
    double *value,
    char *unit,
    char *formatted
    ) {
    sector_market_cap_amount_t *sector_market_cap_amount_local_var = malloc(sizeof(sector_market_cap_amount_t));
    if (!sector_market_cap_amount_local_var) {
        return NULL;
    }
    memset(sector_market_cap_amount_local_var, 0, sizeof(sector_market_cap_amount_t));
    sector_market_cap_amount_local_var->_library_owned = 1;
    sector_market_cap_amount_local_var->value = value;
    sector_market_cap_amount_local_var->unit = unit;
    sector_market_cap_amount_local_var->formatted = formatted;
    return sector_market_cap_amount_local_var;
}

sector_market_cap_amount_t *sector_market_cap_amount_create(
    double *value,
    char *unit,
    char *formatted
    ) {
    double *value_copy = NULL;
    if (value) {
        value_copy = malloc(sizeof(double));
        if (value_copy) *value_copy = *value;
    }
    sector_market_cap_amount_t *result = sector_market_cap_amount_create_internal (
        value_copy,
        unit,
        formatted
        );
    if (!result) {
        free(value_copy);
    }
    return result;
}

void sector_market_cap_amount_free(sector_market_cap_amount_t *sector_market_cap_amount) {
    if(NULL == sector_market_cap_amount){
        return ;
    }
    if(sector_market_cap_amount->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sector_market_cap_amount_free");
        return ;
    }
    listEntry_t *listEntry;
    if (sector_market_cap_amount->value) {
        free(sector_market_cap_amount->value);
        sector_market_cap_amount->value = NULL;
    }
    if (sector_market_cap_amount->unit) {
        free(sector_market_cap_amount->unit);
        sector_market_cap_amount->unit = NULL;
    }
    if (sector_market_cap_amount->formatted) {
        free(sector_market_cap_amount->formatted);
        sector_market_cap_amount->formatted = NULL;
    }
    free(sector_market_cap_amount);
}

cJSON *sector_market_cap_amount_convertToJSON(sector_market_cap_amount_t *sector_market_cap_amount) {
    cJSON *item = cJSON_CreateObject();

    // sector_market_cap_amount->value
    if(sector_market_cap_amount->value) {
    if(cJSON_AddNumberToObject(item, "value", *sector_market_cap_amount->value) == NULL) {
    goto fail; //Numeric
    }
    }


    // sector_market_cap_amount->unit
    if(sector_market_cap_amount->unit) {
    if(cJSON_AddStringToObject(item, "unit", sector_market_cap_amount->unit) == NULL) {
    goto fail; //String
    }
    }


    // sector_market_cap_amount->formatted
    if(sector_market_cap_amount->formatted) {
    if(cJSON_AddStringToObject(item, "formatted", sector_market_cap_amount->formatted) == NULL) {
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

sector_market_cap_amount_t *sector_market_cap_amount_parseFromJSON(cJSON *sector_market_cap_amountJSON){

    sector_market_cap_amount_t *sector_market_cap_amount_local_var = NULL;

    // define the local variable for sector_market_cap_amount->value
    double *value_local_var = NULL;

    char *unit_local_str = NULL;

    char *formatted_local_str = NULL;

    // sector_market_cap_amount->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(sector_market_cap_amountJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (value) { 
    if(!cJSON_IsNumber(value))
    {
    goto end; //Numeric
    }
    value_local_var = malloc(sizeof(double));
    if(!value_local_var)
    {
        goto end;
    }
    *value_local_var = value->valuedouble;
    }

    // sector_market_cap_amount->unit
    cJSON *unit = cJSON_GetObjectItemCaseSensitive(sector_market_cap_amountJSON, "unit");
    if (cJSON_IsNull(unit)) {
        unit = NULL;
    }
    if (unit) { 
    if(!cJSON_IsString(unit) && !cJSON_IsNull(unit))
    {
    goto end; //String
    }
    }

    // sector_market_cap_amount->formatted
    cJSON *formatted = cJSON_GetObjectItemCaseSensitive(sector_market_cap_amountJSON, "formatted");
    if (cJSON_IsNull(formatted)) {
        formatted = NULL;
    }
    if (formatted) { 
    if(!cJSON_IsString(formatted) && !cJSON_IsNull(formatted))
    {
    goto end; //String
    }
    }


    if (unit && !cJSON_IsNull(unit)) unit_local_str = strdup(unit->valuestring);
    if (formatted && !cJSON_IsNull(formatted)) formatted_local_str = strdup(formatted->valuestring);

    sector_market_cap_amount_local_var = sector_market_cap_amount_create_internal (
        value_local_var,
        unit_local_str,
        formatted_local_str
        );

    if (!sector_market_cap_amount_local_var) {
        goto end;
    }

    return sector_market_cap_amount_local_var;
end:
    if (value_local_var) {
        free(value_local_var);
        value_local_var = NULL;
    }
    if (unit_local_str) {
        free(unit_local_str);
        unit_local_str = NULL;
    }
    if (formatted_local_str) {
        free(formatted_local_str);
        formatted_local_str = NULL;
    }
    return NULL;

}
