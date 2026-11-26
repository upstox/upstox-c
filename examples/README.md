# Upstox Developer API – Example Code

This folder contains **ready-to-use C samples** for the [Upstox API](https://upstox.com/developer/api-documentation/open-api). Each example shows how to call the API using the official Upstox C SDK.

## Why use these samples?

- **Quick start** — Copy-paste examples for common flows (login, orders, market data, portfolio).
- **Correct usage** — Request/response patterns, error handling, and API version usage as recommended by Upstox.
- **Reference** — See how to build `place_order_request_t`, historical data params, and other API payloads, and who frees what.

Use these samples to build trading apps, dashboards, or integrations without guessing request shapes or SDK usage.

## Prerequisites

- **C compiler** (C99) and **CMake** 3.x
- **SDK**: build this repository (see the [root README](../README.md)); include headers from the repo root, e.g. `#include "upstox_client/upstox.h"`, and link `upstox_client` (plus `upstox_feeder` for websocket samples)
- **Upstox developer account** and API credentials (client ID, client secret, redirect URI).
- **Access token** for authenticated APIs (obtain via [Login API](login/) samples).

For full setup, sandbox mode, and auth flow, see the main [Upstox C SDK README](../README.md) in the repo root.

## Folder structure

Samples are grouped by API area. Each `.md` file contains one or more complete C programs (`main()` included) you can compile after replacing placeholders like `{your_access_token}` and `{your_client_id}`.

Every program follows the same pattern: call `apiClient_setupGlobalEnv()`, create a client with `upstox_client_create(token)`, call `<Tag>API_<operation>(client, ...)`, print the returned model (or `client->errorBody` when it returns `NULL`), free what was allocated, then `apiClient_free(client)` and `apiClient_unsetupGlobalEnv()`.

| Folder | Description |
|--------|-------------|
| [**login/**](login/) | Authentication: get token from auth code, access-token request, logout. |
| [**user/**](user/) | User profile, fund and margin details, IP management, kill switch. |
| [**orders/**](orders/) | Order lifecycle: place (single/multi, v2 & v3), modify, cancel, order book, order details, order history, trades, historical trades, exit all positions. |
| [**portfolio/**](portfolio/) | Positions, holdings, MTF positions, convert positions. |
| [**market-quote/**](market-quote/) | LTP, full market quotes (v2 & v3), OHLC (v2 & v3), option Greeks. |
| [**historical-data/**](historical-data/) | Historical and intraday candle data (v2 & v3). |
| [**option-chain/**](option-chain/) | Option contracts, put-call option chain. |
| [**expired-instruments/**](expired-instruments/) | Expiries, expired future/option contracts, expired historical candle data. |
| [**market-information/**](market-information/) | Exchange status, market timings, market holidays, OI, change in OI, PCR, max pain, FII, and DII. |
| [**smartlist/**](smartlist/) | Analytics-enriched smartlists for options, futures, and MTF stocks. |
| [**ipo/**](ipo/) | IPO listing (by status/issue type), IPO details by id, and IPO orders — apply, list, fetch by order id and cancel. |
| [**us-stocks/**](us-stocks/) | US stocks: place/cancel orders, order book and details, charge estimate and margin, funds, holdings, and US market status, holidays and timings. |
| [**gtt-orders/**](gtt-orders/) | Place, modify, cancel, and get details for GTT (Good Till Triggered) orders. |
| [**margins/**](margins/) | Margin details. |
| [**charges/**](charges/) | Brokerage details. |
| [**mutual-funds-api/**](mutual-funds-api/) | Mutual fund holdings, orders, order details, and SIPs. |
| [**payments-api/**](payments-api/) | Payin and payout history. |
| [**payout/**](payout/) | Payout history, payout modes, and initiate/modify/cancel payout. |
| [**news/**](news/) | News articles by instrument keys, positions, or holdings. |
| [**fundamentals/**](fundamentals/) | Company profile, balance sheet, cash flow, income statement, key ratios, share holdings, corporate actions, and competitors. |
| [**trade-profit-and-loss/**](trade-profit-and-loss/) | P&amp;L report, report metadata, trade charges. |
| [**strategies/**](strategies/) | Ready-to-run options strategy examples for Nifty 50 (bullish, bearish, neutral, others). |
| [**websocket/**](websocket/) | Live market data (`market_data_streamer_v3_t`) and order/portfolio updates (`portfolio_data_streamer_t`) over WebSocket. |

### Options Strategies

Each strategy program searches for the required Nifty 50 option legs using the Instruments API (`InstrumentsAPI_searchInstrument`) and places market orders via the v3 Order API (`OrderV3API_placeOrderV3`). Build them with `-DUPSTOX_BUILD_EXAMPLES=ON`; they read the token from `UPSTOX_ACCESS_TOKEN` and place real orders.

#### [Bullish](strategies/bullish/)

| File | Strategy | Legs |
|------|----------|------|
| [buy_call.c](strategies/bullish/code/buy_call.c) | [**Buy Call**](strategies/bullish/README.md#buy-call--codebuy_callc) | BUY ATM CE |
| [sell_put.c](strategies/bullish/code/sell_put.c) | [**Sell Put**](strategies/bullish/README.md#sell-put--codesell_putc) | SELL ATM PE |
| [bull_call_spread.c](strategies/bullish/code/bull_call_spread.c) | [**Bull Call Spread**](strategies/bullish/README.md#bull-call-spread--codebull_call_spreadc) | BUY ATM CE + SELL ATM+1 CE |
| [bull_put_spread.c](strategies/bullish/code/bull_put_spread.c) | [**Bull Put Spread**](strategies/bullish/README.md#bull-put-spread--codebull_put_spreadc) | SELL ATM PE + BUY ATM-1 PE |
| [bull_butterfly.c](strategies/bullish/code/bull_butterfly.c) | [**Bull Butterfly**](strategies/bullish/README.md#bull-butterfly--codebull_butterflyc) | BUY ATM CE + SELL 2× ATM+1 CE + BUY ATM+2 CE |
| [bull_condor.c](strategies/bullish/code/bull_condor.c) | [**Bull Condor**](strategies/bullish/README.md#bull-condor--codebull_condorc) | BUY ATM CE + SELL ATM+1 CE + SELL ATM+2 CE + BUY ATM+3 CE |
| [long_calendar_call.c](strategies/bullish/code/long_calendar_call.c) | [**Long Calendar with Calls**](strategies/bullish/README.md#long-calendar-with-calls--codelong_calendar_callc) | SELL current-week ATM CE + BUY next-week ATM CE |
| [long_synthetic_future.c](strategies/bullish/code/long_synthetic_future.c) | [**Long Synthetic Future**](strategies/bullish/README.md#long-synthetic-future--codelong_synthetic_futurec) | BUY ATM CE + SELL ATM PE |
| [call_ratio_back_spread.c](strategies/bullish/code/call_ratio_back_spread.c) | [**Call Ratio Back Spread**](strategies/bullish/README.md#call-ratio-back-spread--codecall_ratio_back_spreadc) | SELL 1× ATM CE + BUY 2× ATM+1 CE |
| [range_forward.c](strategies/bullish/code/range_forward.c) | [**Range Forward**](strategies/bullish/README.md#range-forward--coderange_forwardc) | SELL ATM-1 PE + BUY ATM+1 CE |

#### [Bearish](strategies/bearish/)

| File | Strategy | Legs |
|------|----------|------|
| [buy_put.c](strategies/bearish/code/buy_put.c) | [**Buy Put**](strategies/bearish/README.md#buy-put--codebuy_putc) | BUY ATM PE |
| [sell_call.c](strategies/bearish/code/sell_call.c) | [**Sell Call**](strategies/bearish/README.md#sell-call--codesell_callc) | SELL ATM CE |
| [bear_call_spread.c](strategies/bearish/code/bear_call_spread.c) | [**Bear Call Spread**](strategies/bearish/README.md#bear-call-spread--codebear_call_spreadc) | SELL ATM CE + BUY ATM+1 CE |
| [bear_put_spread.c](strategies/bearish/code/bear_put_spread.c) | [**Bear Put Spread**](strategies/bearish/README.md#bear-put-spread--codebear_put_spreadc) | BUY ATM PE + SELL ATM-1 PE |
| [bear_butterfly.c](strategies/bearish/code/bear_butterfly.c) | [**Bear Butterfly**](strategies/bearish/README.md#bear-butterfly--codebear_butterflyc) | BUY ATM PE + SELL 2× ATM-1 PE + BUY ATM-2 PE |
| [bear_condor.c](strategies/bearish/code/bear_condor.c) | [**Bear Condor**](strategies/bearish/README.md#bear-condor--codebear_condorc) | BUY ATM PE + SELL ATM-1 PE + SELL ATM-2 PE + BUY ATM-3 PE |
| [long_calendar_put.c](strategies/bearish/code/long_calendar_put.c) | [**Long Calendar with Puts**](strategies/bearish/README.md#long-calendar-with-puts--codelong_calendar_putc) | SELL current-week ATM PE + BUY next-week ATM PE |
| [short_synthetic_future.c](strategies/bearish/code/short_synthetic_future.c) | [**Short Synthetic Future**](strategies/bearish/README.md#short-synthetic-future--codeshort_synthetic_futurec) | SELL ATM CE + BUY ATM PE |
| [put_ratio_back_spread.c](strategies/bearish/code/put_ratio_back_spread.c) | [**Put Ratio Back Spread**](strategies/bearish/README.md#put-ratio-back-spread--codeput_ratio_back_spreadc) | SELL 1× ATM PE + BUY 2× ATM-1 PE |
| [risk_reversal.c](strategies/bearish/code/risk_reversal.c) | [**Risk Reversal**](strategies/bearish/README.md#risk-reversal--coderisk_reversalc) | SELL ATM+1 CE + BUY ATM-1 PE |

#### [Neutral](strategies/neutral/)

| File | Strategy | Legs |
|------|----------|------|
| [short_straddle.c](strategies/neutral/code/short_straddle.c) | [**Short Straddle**](strategies/neutral/README.md#short-straddle--codeshort_straddlec) | SELL ATM CE + SELL ATM PE |
| [short_strangle.c](strategies/neutral/code/short_strangle.c) | [**Short Strangle**](strategies/neutral/README.md#short-strangle--codeshort_stranglec) | SELL ATM+1 CE + SELL ATM-1 PE |
| [iron_butterfly.c](strategies/neutral/code/iron_butterfly.c) | [**Iron Butterfly**](strategies/neutral/README.md#iron-butterfly--codeiron_butterflyc) | SELL ATM CE + SELL ATM PE + BUY ATM+2 CE + BUY ATM-2 PE |
| [batman.c](strategies/neutral/code/batman.c) | [**Batman**](strategies/neutral/README.md#batman--codebatmanc) | BUY ATM CE + SELL 2× ATM+1 CE + BUY ATM+2 CE + BUY ATM PE + SELL 2× ATM-1 PE + BUY ATM-2 PE |
| [short_iron_condor.c](strategies/neutral/code/short_iron_condor.c) | [**Short Iron Condor**](strategies/neutral/README.md#short-iron-condor--codeshort_iron_condorc) | SELL ATM+1 CE + BUY ATM+2 CE + SELL ATM-1 PE + BUY ATM-2 PE |

#### [Others](strategies/others/)

| File | Strategy | Legs |
|------|----------|------|
| [long_straddle.c](strategies/others/code/long_straddle.c) | [**Long Straddle**](strategies/others/README.md#long-straddle--codelong_straddlec) | BUY ATM CE + BUY ATM PE |
| [long_strangle.c](strategies/others/code/long_strangle.c) | [**Long Strangle**](strategies/others/README.md#long-strangle--codelong_stranglec) | BUY ATM+1 CE + BUY ATM-1 PE |
| [call_ratio_spread.c](strategies/others/code/call_ratio_spread.c) | [**Call Ratio Spread**](strategies/others/README.md#call-ratio-spread--codecall_ratio_spreadc) | BUY 1× ATM CE + SELL 2× ATM+1 CE |
| [put_ratio_spread.c](strategies/others/code/put_ratio_spread.c) | [**Put Ratio Spread**](strategies/others/README.md#put-ratio-spread--codeput_ratio_spreadc) | BUY 1× ATM PE + SELL 2× ATM-1 PE |
| [long_iron_butterfly.c](strategies/others/code/long_iron_butterfly.c) | [**Long Iron Butterfly**](strategies/others/README.md#long-iron-butterfly--codelong_iron_butterflyc) | BUY ATM CE + BUY ATM PE + SELL ATM+2 CE + SELL ATM-2 PE |
| [long_iron_condor.c](strategies/others/code/long_iron_condor.c) | [**Long Iron Condor**](strategies/others/README.md#long-iron-condor--codelong_iron_condorc) | BUY ATM+1 CE + SELL ATM+2 CE + BUY ATM-1 PE + SELL ATM-2 PE |
| [strip.c](strategies/others/code/strip.c) | [**Strip**](strategies/others/README.md#strip--codestripc) | BUY 1× ATM CE + BUY 2× ATM PE |
| [strap.c](strategies/others/code/strap.c) | [**Strap**](strategies/others/README.md#strap--codestrapc) | BUY 2× ATM CE + BUY 1× ATM PE |

## Documentation

- [Upstox API Documentation](https://upstox.com/developer/api-documentation)
- [Upstox C SDK API reference](../docs/API_REFERENCE.md)
