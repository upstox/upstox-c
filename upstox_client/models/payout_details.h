/*
 * payout_details.h
 *
 * 
 */

#ifndef _payout_details_H_
#define _payout_details_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payout_details_t payout_details_t;




typedef struct payout_details_t {
    char *status; // string
    char *mode; // string
    double *amount; //numeric
    char *currency; // string
    char *eta; // string
    char *message; // string
    char *transaction_id; // string
    char *created_at; // string
    char *bank_name; // string
    char *transaction_fee; // string

    int _library_owned; // Is the library responsible for freeing this object?
} payout_details_t;

payout_details_t *payout_details_create(
    char *status,
    char *mode,
    double *amount,
    char *currency,
    char *eta,
    char *message,
    char *transaction_id,
    char *created_at,
    char *bank_name,
    char *transaction_fee
);

void payout_details_free(payout_details_t *payout_details);

payout_details_t *payout_details_parseFromJSON(cJSON *payout_detailsJSON);

cJSON *payout_details_convertToJSON(payout_details_t *payout_details);

#endif /* _payout_details_H_ */

