#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "analytics_data.h"



static analytics_data_t *analytics_data_create_internal(
    double *vega,
    double *theta,
    double *gamma,
    double *delta,
    double *iv,
    double *pop
    ) {
    analytics_data_t *analytics_data_local_var = malloc(sizeof(analytics_data_t));
    if (!analytics_data_local_var) {
        return NULL;
    }
    memset(analytics_data_local_var, 0, sizeof(analytics_data_t));
    analytics_data_local_var->_library_owned = 1;
    analytics_data_local_var->vega = vega;
    analytics_data_local_var->theta = theta;
    analytics_data_local_var->gamma = gamma;
    analytics_data_local_var->delta = delta;
    analytics_data_local_var->iv = iv;
    analytics_data_local_var->pop = pop;
    return analytics_data_local_var;
}

analytics_data_t *analytics_data_create(
    double *vega,
    double *theta,
    double *gamma,
    double *delta,
    double *iv,
    double *pop
    ) {
    double *vega_copy = NULL;
    if (vega) {
        vega_copy = malloc(sizeof(double));
        if (vega_copy) *vega_copy = *vega;
    }
    double *theta_copy = NULL;
    if (theta) {
        theta_copy = malloc(sizeof(double));
        if (theta_copy) *theta_copy = *theta;
    }
    double *gamma_copy = NULL;
    if (gamma) {
        gamma_copy = malloc(sizeof(double));
        if (gamma_copy) *gamma_copy = *gamma;
    }
    double *delta_copy = NULL;
    if (delta) {
        delta_copy = malloc(sizeof(double));
        if (delta_copy) *delta_copy = *delta;
    }
    double *iv_copy = NULL;
    if (iv) {
        iv_copy = malloc(sizeof(double));
        if (iv_copy) *iv_copy = *iv;
    }
    double *pop_copy = NULL;
    if (pop) {
        pop_copy = malloc(sizeof(double));
        if (pop_copy) *pop_copy = *pop;
    }
    analytics_data_t *result = analytics_data_create_internal (
        vega_copy,
        theta_copy,
        gamma_copy,
        delta_copy,
        iv_copy,
        pop_copy
        );
    if (!result) {
        free(vega_copy);
        free(theta_copy);
        free(gamma_copy);
        free(delta_copy);
        free(iv_copy);
        free(pop_copy);
    }
    return result;
}

void analytics_data_free(analytics_data_t *analytics_data) {
    if(NULL == analytics_data){
        return ;
    }
    if(analytics_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "analytics_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (analytics_data->vega) {
        free(analytics_data->vega);
        analytics_data->vega = NULL;
    }
    if (analytics_data->theta) {
        free(analytics_data->theta);
        analytics_data->theta = NULL;
    }
    if (analytics_data->gamma) {
        free(analytics_data->gamma);
        analytics_data->gamma = NULL;
    }
    if (analytics_data->delta) {
        free(analytics_data->delta);
        analytics_data->delta = NULL;
    }
    if (analytics_data->iv) {
        free(analytics_data->iv);
        analytics_data->iv = NULL;
    }
    if (analytics_data->pop) {
        free(analytics_data->pop);
        analytics_data->pop = NULL;
    }
    free(analytics_data);
}

cJSON *analytics_data_convertToJSON(analytics_data_t *analytics_data) {
    cJSON *item = cJSON_CreateObject();

    // analytics_data->vega
    if(analytics_data->vega) {
    if(cJSON_AddNumberToObject(item, "vega", *analytics_data->vega) == NULL) {
    goto fail; //Numeric
    }
    }


    // analytics_data->theta
    if(analytics_data->theta) {
    if(cJSON_AddNumberToObject(item, "theta", *analytics_data->theta) == NULL) {
    goto fail; //Numeric
    }
    }


    // analytics_data->gamma
    if(analytics_data->gamma) {
    if(cJSON_AddNumberToObject(item, "gamma", *analytics_data->gamma) == NULL) {
    goto fail; //Numeric
    }
    }


    // analytics_data->delta
    if(analytics_data->delta) {
    if(cJSON_AddNumberToObject(item, "delta", *analytics_data->delta) == NULL) {
    goto fail; //Numeric
    }
    }


    // analytics_data->iv
    if(analytics_data->iv) {
    if(cJSON_AddNumberToObject(item, "iv", *analytics_data->iv) == NULL) {
    goto fail; //Numeric
    }
    }


    // analytics_data->pop
    if(analytics_data->pop) {
    if(cJSON_AddNumberToObject(item, "pop", *analytics_data->pop) == NULL) {
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

analytics_data_t *analytics_data_parseFromJSON(cJSON *analytics_dataJSON){

    analytics_data_t *analytics_data_local_var = NULL;

    // define the local variable for analytics_data->vega
    double *vega_local_var = NULL;

    // define the local variable for analytics_data->theta
    double *theta_local_var = NULL;

    // define the local variable for analytics_data->gamma
    double *gamma_local_var = NULL;

    // define the local variable for analytics_data->delta
    double *delta_local_var = NULL;

    // define the local variable for analytics_data->iv
    double *iv_local_var = NULL;

    // define the local variable for analytics_data->pop
    double *pop_local_var = NULL;

    // analytics_data->vega
    cJSON *vega = cJSON_GetObjectItemCaseSensitive(analytics_dataJSON, "vega");
    if (cJSON_IsNull(vega)) {
        vega = NULL;
    }
    if (vega) { 
    if(!cJSON_IsNumber(vega))
    {
    goto end; //Numeric
    }
    vega_local_var = malloc(sizeof(double));
    if(!vega_local_var)
    {
        goto end;
    }
    *vega_local_var = vega->valuedouble;
    }

    // analytics_data->theta
    cJSON *theta = cJSON_GetObjectItemCaseSensitive(analytics_dataJSON, "theta");
    if (cJSON_IsNull(theta)) {
        theta = NULL;
    }
    if (theta) { 
    if(!cJSON_IsNumber(theta))
    {
    goto end; //Numeric
    }
    theta_local_var = malloc(sizeof(double));
    if(!theta_local_var)
    {
        goto end;
    }
    *theta_local_var = theta->valuedouble;
    }

    // analytics_data->gamma
    cJSON *gamma = cJSON_GetObjectItemCaseSensitive(analytics_dataJSON, "gamma");
    if (cJSON_IsNull(gamma)) {
        gamma = NULL;
    }
    if (gamma) { 
    if(!cJSON_IsNumber(gamma))
    {
    goto end; //Numeric
    }
    gamma_local_var = malloc(sizeof(double));
    if(!gamma_local_var)
    {
        goto end;
    }
    *gamma_local_var = gamma->valuedouble;
    }

    // analytics_data->delta
    cJSON *delta = cJSON_GetObjectItemCaseSensitive(analytics_dataJSON, "delta");
    if (cJSON_IsNull(delta)) {
        delta = NULL;
    }
    if (delta) { 
    if(!cJSON_IsNumber(delta))
    {
    goto end; //Numeric
    }
    delta_local_var = malloc(sizeof(double));
    if(!delta_local_var)
    {
        goto end;
    }
    *delta_local_var = delta->valuedouble;
    }

    // analytics_data->iv
    cJSON *iv = cJSON_GetObjectItemCaseSensitive(analytics_dataJSON, "iv");
    if (cJSON_IsNull(iv)) {
        iv = NULL;
    }
    if (iv) { 
    if(!cJSON_IsNumber(iv))
    {
    goto end; //Numeric
    }
    iv_local_var = malloc(sizeof(double));
    if(!iv_local_var)
    {
        goto end;
    }
    *iv_local_var = iv->valuedouble;
    }

    // analytics_data->pop
    cJSON *pop = cJSON_GetObjectItemCaseSensitive(analytics_dataJSON, "pop");
    if (cJSON_IsNull(pop)) {
        pop = NULL;
    }
    if (pop) { 
    if(!cJSON_IsNumber(pop))
    {
    goto end; //Numeric
    }
    pop_local_var = malloc(sizeof(double));
    if(!pop_local_var)
    {
        goto end;
    }
    *pop_local_var = pop->valuedouble;
    }



    analytics_data_local_var = analytics_data_create_internal (
        vega_local_var,
        theta_local_var,
        gamma_local_var,
        delta_local_var,
        iv_local_var,
        pop_local_var
        );

    if (!analytics_data_local_var) {
        goto end;
    }

    return analytics_data_local_var;
end:
    if (vega_local_var) {
        free(vega_local_var);
        vega_local_var = NULL;
    }
    if (theta_local_var) {
        free(theta_local_var);
        theta_local_var = NULL;
    }
    if (gamma_local_var) {
        free(gamma_local_var);
        gamma_local_var = NULL;
    }
    if (delta_local_var) {
        free(delta_local_var);
        delta_local_var = NULL;
    }
    if (iv_local_var) {
        free(iv_local_var);
        iv_local_var = NULL;
    }
    if (pop_local_var) {
        free(pop_local_var);
        pop_local_var = NULL;
    }
    return NULL;

}
