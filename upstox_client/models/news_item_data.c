#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "news_item_data.h"



static news_item_data_t *news_item_data_create_internal(
    char *heading,
    char *summary,
    char *thumbnail,
    char *article_link,
    long *published_time
    ) {
    news_item_data_t *news_item_data_local_var = malloc(sizeof(news_item_data_t));
    if (!news_item_data_local_var) {
        return NULL;
    }
    memset(news_item_data_local_var, 0, sizeof(news_item_data_t));
    news_item_data_local_var->_library_owned = 1;
    news_item_data_local_var->heading = heading;
    news_item_data_local_var->summary = summary;
    news_item_data_local_var->thumbnail = thumbnail;
    news_item_data_local_var->article_link = article_link;
    news_item_data_local_var->published_time = published_time;
    return news_item_data_local_var;
}

news_item_data_t *news_item_data_create(
    char *heading,
    char *summary,
    char *thumbnail,
    char *article_link,
    long *published_time
    ) {
    long *published_time_copy = NULL;
    if (published_time) {
        published_time_copy = malloc(sizeof(long));
        if (published_time_copy) *published_time_copy = *published_time;
    }
    news_item_data_t *result = news_item_data_create_internal (
        heading,
        summary,
        thumbnail,
        article_link,
        published_time_copy
        );
    if (!result) {
        free(published_time_copy);
    }
    return result;
}

void news_item_data_free(news_item_data_t *news_item_data) {
    if(NULL == news_item_data){
        return ;
    }
    if(news_item_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "news_item_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (news_item_data->heading) {
        free(news_item_data->heading);
        news_item_data->heading = NULL;
    }
    if (news_item_data->summary) {
        free(news_item_data->summary);
        news_item_data->summary = NULL;
    }
    if (news_item_data->thumbnail) {
        free(news_item_data->thumbnail);
        news_item_data->thumbnail = NULL;
    }
    if (news_item_data->article_link) {
        free(news_item_data->article_link);
        news_item_data->article_link = NULL;
    }
    if (news_item_data->published_time) {
        free(news_item_data->published_time);
        news_item_data->published_time = NULL;
    }
    free(news_item_data);
}

cJSON *news_item_data_convertToJSON(news_item_data_t *news_item_data) {
    cJSON *item = cJSON_CreateObject();

    // news_item_data->heading
    if(news_item_data->heading) {
    if(cJSON_AddStringToObject(item, "heading", news_item_data->heading) == NULL) {
    goto fail; //String
    }
    }


    // news_item_data->summary
    if(news_item_data->summary) {
    if(cJSON_AddStringToObject(item, "summary", news_item_data->summary) == NULL) {
    goto fail; //String
    }
    }


    // news_item_data->thumbnail
    if(news_item_data->thumbnail) {
    if(cJSON_AddStringToObject(item, "thumbnail", news_item_data->thumbnail) == NULL) {
    goto fail; //String
    }
    }


    // news_item_data->article_link
    if(news_item_data->article_link) {
    if(cJSON_AddStringToObject(item, "article_link", news_item_data->article_link) == NULL) {
    goto fail; //String
    }
    }


    // news_item_data->published_time
    if(news_item_data->published_time) {
    if(cJSON_AddNumberToObject(item, "published_time", *news_item_data->published_time) == NULL) {
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

news_item_data_t *news_item_data_parseFromJSON(cJSON *news_item_dataJSON){

    news_item_data_t *news_item_data_local_var = NULL;

    char *heading_local_str = NULL;

    char *summary_local_str = NULL;

    char *thumbnail_local_str = NULL;

    char *article_link_local_str = NULL;

    // define the local variable for news_item_data->published_time
    long *published_time_local_var = NULL;

    // news_item_data->heading
    cJSON *heading = cJSON_GetObjectItemCaseSensitive(news_item_dataJSON, "heading");
    if (cJSON_IsNull(heading)) {
        heading = NULL;
    }
    if (heading) { 
    if(!cJSON_IsString(heading) && !cJSON_IsNull(heading))
    {
    goto end; //String
    }
    }

    // news_item_data->summary
    cJSON *summary = cJSON_GetObjectItemCaseSensitive(news_item_dataJSON, "summary");
    if (cJSON_IsNull(summary)) {
        summary = NULL;
    }
    if (summary) { 
    if(!cJSON_IsString(summary) && !cJSON_IsNull(summary))
    {
    goto end; //String
    }
    }

    // news_item_data->thumbnail
    cJSON *thumbnail = cJSON_GetObjectItemCaseSensitive(news_item_dataJSON, "thumbnail");
    if (cJSON_IsNull(thumbnail)) {
        thumbnail = NULL;
    }
    if (thumbnail) { 
    if(!cJSON_IsString(thumbnail) && !cJSON_IsNull(thumbnail))
    {
    goto end; //String
    }
    }

    // news_item_data->article_link
    cJSON *article_link = cJSON_GetObjectItemCaseSensitive(news_item_dataJSON, "article_link");
    if (cJSON_IsNull(article_link)) {
        article_link = NULL;
    }
    if (article_link) { 
    if(!cJSON_IsString(article_link) && !cJSON_IsNull(article_link))
    {
    goto end; //String
    }
    }

    // news_item_data->published_time
    cJSON *published_time = cJSON_GetObjectItemCaseSensitive(news_item_dataJSON, "published_time");
    if (cJSON_IsNull(published_time)) {
        published_time = NULL;
    }
    if (published_time) { 
    if(!cJSON_IsNumber(published_time))
    {
    goto end; //Numeric
    }
    published_time_local_var = malloc(sizeof(long));
    if(!published_time_local_var)
    {
        goto end;
    }
    *published_time_local_var = published_time->valuedouble;
    }


    if (heading && !cJSON_IsNull(heading)) heading_local_str = strdup(heading->valuestring);
    if (summary && !cJSON_IsNull(summary)) summary_local_str = strdup(summary->valuestring);
    if (thumbnail && !cJSON_IsNull(thumbnail)) thumbnail_local_str = strdup(thumbnail->valuestring);
    if (article_link && !cJSON_IsNull(article_link)) article_link_local_str = strdup(article_link->valuestring);

    news_item_data_local_var = news_item_data_create_internal (
        heading_local_str,
        summary_local_str,
        thumbnail_local_str,
        article_link_local_str,
        published_time_local_var
        );

    if (!news_item_data_local_var) {
        goto end;
    }

    return news_item_data_local_var;
end:
    if (heading_local_str) {
        free(heading_local_str);
        heading_local_str = NULL;
    }
    if (summary_local_str) {
        free(summary_local_str);
        summary_local_str = NULL;
    }
    if (thumbnail_local_str) {
        free(thumbnail_local_str);
        thumbnail_local_str = NULL;
    }
    if (article_link_local_str) {
        free(article_link_local_str);
        article_link_local_str = NULL;
    }
    if (published_time_local_var) {
        free(published_time_local_var);
        published_time_local_var = NULL;
    }
    return NULL;

}
