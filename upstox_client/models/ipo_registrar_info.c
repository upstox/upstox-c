#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_registrar_info.h"



static ipo_registrar_info_t *ipo_registrar_info_create_internal(
    char *name,
    char *email,
    char *contact_name,
    char *contact_number,
    char *website,
    char *registrar
    ) {
    ipo_registrar_info_t *ipo_registrar_info_local_var = malloc(sizeof(ipo_registrar_info_t));
    if (!ipo_registrar_info_local_var) {
        return NULL;
    }
    memset(ipo_registrar_info_local_var, 0, sizeof(ipo_registrar_info_t));
    ipo_registrar_info_local_var->_library_owned = 1;
    ipo_registrar_info_local_var->name = name;
    ipo_registrar_info_local_var->email = email;
    ipo_registrar_info_local_var->contact_name = contact_name;
    ipo_registrar_info_local_var->contact_number = contact_number;
    ipo_registrar_info_local_var->website = website;
    ipo_registrar_info_local_var->registrar = registrar;
    return ipo_registrar_info_local_var;
}

ipo_registrar_info_t *ipo_registrar_info_create(
    char *name,
    char *email,
    char *contact_name,
    char *contact_number,
    char *website,
    char *registrar
    ) {
    ipo_registrar_info_t *result = ipo_registrar_info_create_internal (
        name,
        email,
        contact_name,
        contact_number,
        website,
        registrar
        );
    if (!result) {
    }
    return result;
}

void ipo_registrar_info_free(ipo_registrar_info_t *ipo_registrar_info) {
    if(NULL == ipo_registrar_info){
        return ;
    }
    if(ipo_registrar_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_registrar_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_registrar_info->name) {
        free(ipo_registrar_info->name);
        ipo_registrar_info->name = NULL;
    }
    if (ipo_registrar_info->email) {
        free(ipo_registrar_info->email);
        ipo_registrar_info->email = NULL;
    }
    if (ipo_registrar_info->contact_name) {
        free(ipo_registrar_info->contact_name);
        ipo_registrar_info->contact_name = NULL;
    }
    if (ipo_registrar_info->contact_number) {
        free(ipo_registrar_info->contact_number);
        ipo_registrar_info->contact_number = NULL;
    }
    if (ipo_registrar_info->website) {
        free(ipo_registrar_info->website);
        ipo_registrar_info->website = NULL;
    }
    if (ipo_registrar_info->registrar) {
        free(ipo_registrar_info->registrar);
        ipo_registrar_info->registrar = NULL;
    }
    free(ipo_registrar_info);
}

cJSON *ipo_registrar_info_convertToJSON(ipo_registrar_info_t *ipo_registrar_info) {
    cJSON *item = cJSON_CreateObject();

    // ipo_registrar_info->name
    if(ipo_registrar_info->name) {
    if(cJSON_AddStringToObject(item, "name", ipo_registrar_info->name) == NULL) {
    goto fail; //String
    }
    }


    // ipo_registrar_info->email
    if(ipo_registrar_info->email) {
    if(cJSON_AddStringToObject(item, "email", ipo_registrar_info->email) == NULL) {
    goto fail; //String
    }
    }


    // ipo_registrar_info->contact_name
    if(ipo_registrar_info->contact_name) {
    if(cJSON_AddStringToObject(item, "contact_name", ipo_registrar_info->contact_name) == NULL) {
    goto fail; //String
    }
    }


    // ipo_registrar_info->contact_number
    if(ipo_registrar_info->contact_number) {
    if(cJSON_AddStringToObject(item, "contact_number", ipo_registrar_info->contact_number) == NULL) {
    goto fail; //String
    }
    }


    // ipo_registrar_info->website
    if(ipo_registrar_info->website) {
    if(cJSON_AddStringToObject(item, "website", ipo_registrar_info->website) == NULL) {
    goto fail; //String
    }
    }


    // ipo_registrar_info->registrar
    if(ipo_registrar_info->registrar) {
    if(cJSON_AddStringToObject(item, "registrar", ipo_registrar_info->registrar) == NULL) {
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

ipo_registrar_info_t *ipo_registrar_info_parseFromJSON(cJSON *ipo_registrar_infoJSON){

    ipo_registrar_info_t *ipo_registrar_info_local_var = NULL;

    char *name_local_str = NULL;

    char *email_local_str = NULL;

    char *contact_name_local_str = NULL;

    char *contact_number_local_str = NULL;

    char *website_local_str = NULL;

    char *registrar_local_str = NULL;

    // ipo_registrar_info->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(ipo_registrar_infoJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // ipo_registrar_info->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(ipo_registrar_infoJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (email) { 
    if(!cJSON_IsString(email) && !cJSON_IsNull(email))
    {
    goto end; //String
    }
    }

    // ipo_registrar_info->contact_name
    cJSON *contact_name = cJSON_GetObjectItemCaseSensitive(ipo_registrar_infoJSON, "contact_name");
    if (cJSON_IsNull(contact_name)) {
        contact_name = NULL;
    }
    if (contact_name) { 
    if(!cJSON_IsString(contact_name) && !cJSON_IsNull(contact_name))
    {
    goto end; //String
    }
    }

    // ipo_registrar_info->contact_number
    cJSON *contact_number = cJSON_GetObjectItemCaseSensitive(ipo_registrar_infoJSON, "contact_number");
    if (cJSON_IsNull(contact_number)) {
        contact_number = NULL;
    }
    if (contact_number) { 
    if(!cJSON_IsString(contact_number) && !cJSON_IsNull(contact_number))
    {
    goto end; //String
    }
    }

    // ipo_registrar_info->website
    cJSON *website = cJSON_GetObjectItemCaseSensitive(ipo_registrar_infoJSON, "website");
    if (cJSON_IsNull(website)) {
        website = NULL;
    }
    if (website) { 
    if(!cJSON_IsString(website) && !cJSON_IsNull(website))
    {
    goto end; //String
    }
    }

    // ipo_registrar_info->registrar
    cJSON *registrar = cJSON_GetObjectItemCaseSensitive(ipo_registrar_infoJSON, "registrar");
    if (cJSON_IsNull(registrar)) {
        registrar = NULL;
    }
    if (registrar) { 
    if(!cJSON_IsString(registrar) && !cJSON_IsNull(registrar))
    {
    goto end; //String
    }
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (email && !cJSON_IsNull(email)) email_local_str = strdup(email->valuestring);
    if (contact_name && !cJSON_IsNull(contact_name)) contact_name_local_str = strdup(contact_name->valuestring);
    if (contact_number && !cJSON_IsNull(contact_number)) contact_number_local_str = strdup(contact_number->valuestring);
    if (website && !cJSON_IsNull(website)) website_local_str = strdup(website->valuestring);
    if (registrar && !cJSON_IsNull(registrar)) registrar_local_str = strdup(registrar->valuestring);

    ipo_registrar_info_local_var = ipo_registrar_info_create_internal (
        name_local_str,
        email_local_str,
        contact_name_local_str,
        contact_number_local_str,
        website_local_str,
        registrar_local_str
        );

    if (!ipo_registrar_info_local_var) {
        goto end;
    }

    return ipo_registrar_info_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (email_local_str) {
        free(email_local_str);
        email_local_str = NULL;
    }
    if (contact_name_local_str) {
        free(contact_name_local_str);
        contact_name_local_str = NULL;
    }
    if (contact_number_local_str) {
        free(contact_number_local_str);
        contact_number_local_str = NULL;
    }
    if (website_local_str) {
        free(website_local_str);
        website_local_str = NULL;
    }
    if (registrar_local_str) {
        free(registrar_local_str);
        registrar_local_str = NULL;
    }
    return NULL;

}
