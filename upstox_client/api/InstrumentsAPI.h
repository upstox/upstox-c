#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/search_instrument_response.h"


// Search instruments
//
// This API provides the functionality to retrieve the instrument details for searched query
//
search_instrument_response_t*
InstrumentsAPI_searchInstrument(apiClient_t *apiClient, char *query, char *exchanges, char *segments, char *instrument_types, char *expiry, int *atm_offset, int *page_number, int *records);


