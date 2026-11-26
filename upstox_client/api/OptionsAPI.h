#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/get_option_chain_response.h"
#include "../models/get_option_contract_response.h"


// Get option contracts
//
// This API provides the functionality to retrieve the option contracts
//
get_option_contract_response_t*
OptionsAPI_getOptionContracts(apiClient_t *apiClient, char *instrument_key, char *expiry_date);


// Get option chain
//
// This API provides the functionality to retrieve the option chain
//
get_option_chain_response_t*
OptionsAPI_getPutCallOptionChain(apiClient_t *apiClient, char *instrument_key, char *expiry_date);


