#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/get_news_response.h"


// Get News
//
// Fetches news articles for the given instrument keys, or the user's current positions or holdings.
//
get_news_response_t*
NewsAPI_getNews(apiClient_t *apiClient, char *category, char *instrument_keys, int *page_number, int *page_size);


