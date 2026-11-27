cmake_minimum_required (VERSION 2.6...3.10.2)
project (upstox_client C)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=implicit-function-declaration")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=missing-declarations")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=int-conversion")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

find_package(OpenSSL)

if (OPENSSL_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DOPENSSL")
    if(CMAKE_VERSION VERSION_LESS 3.4)
        include_directories(${OPENSSL_INCLUDE_DIR})
        include_directories(${OPENSSL_INCLUDE_DIRS})
        link_directories(${OPENSSL_LIBRARIES})
    endif()
endif()

set(pkgName "upstox_client")

# this default version can be overridden in PreTarget.cmake
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

if( (DEFINED CURL_INCLUDE_DIR) AND (DEFINED CURL_LIBRARIES))
    include_directories(${CURL_INCLUDE_DIR})
    set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
else()
    find_package(CURL 7.58.0 REQUIRED)
    if(CURL_FOUND)
        include_directories(${CURL_INCLUDE_DIR})
        set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
    endif()
endif()

set(SRCS
    upstox_client/upstox.c
    upstox_client/src/list.c
    upstox_client/src/apiKey.c
    upstox_client/src/apiClient.c
    upstox_client/src/binary.c
    upstox_client/external/cJSON.c
    upstox_client/models/object.c
    upstox_client/models/analytics_data.c
    upstox_client/models/analytics_response.c
    upstox_client/models/api_gateway_error_response.c
    upstox_client/models/available_to_trade.c
    upstox_client/models/balance_sheet_data.c
    upstox_client/models/balance_sheet_history_item.c
    upstox_client/models/balance_sheet_response.c
    upstox_client/models/batch_execution_summary.c
    upstox_client/models/brokerage_data.c
    upstox_client/models/brokerage_taxes.c
    upstox_client/models/brokerage_wrapper_data.c
    upstox_client/models/cancel_or_exit_multi_order_data.c
    upstox_client/models/cancel_or_exit_multi_order_response.c
    upstox_client/models/cancel_or_exit_order_error_data.c
    upstox_client/models/cancel_order_data.c
    upstox_client/models/cancel_order_response.c
    upstox_client/models/cancel_order_v3_response.c
    upstox_client/models/cas_eligible_status_data.c
    upstox_client/models/cash_available_to_trade.c
    upstox_client/models/cash_breakdown.c
    upstox_client/models/cash_flow_data.c
    upstox_client/models/cash_flow_entry.c
    upstox_client/models/cash_flow_response.c
    upstox_client/models/cash_margin_used.c
    upstox_client/models/cash_unavailable_to_trade.c
    upstox_client/models/company_profile_data.c
    upstox_client/models/company_profile_response.c
    upstox_client/models/competitor_data.c
    upstox_client/models/competitors_response.c
    upstox_client/models/convert_position_data.c
    upstox_client/models/convert_position_request.c
    upstox_client/models/convert_position_response.c
    upstox_client/models/corporate_action_data.c
    upstox_client/models/corporate_action_event_detail.c
    upstox_client/models/corporate_actions_response.c
    upstox_client/models/delivery_margin.c
    upstox_client/models/depth.c
    upstox_client/models/depth_map.c
    upstox_client/models/dp_plan.c
    upstox_client/models/exchange_timing_data.c
    upstox_client/models/expired_future_data.c
    upstox_client/models/family_member_data.c
    upstox_client/models/financial_statement_entry.c
    upstox_client/models/get_brokerage_response.c
    upstox_client/models/get_exchange_timing_response.c
    upstox_client/models/get_expired_futures_contract_response.c
    upstox_client/models/get_expiries_response.c
    upstox_client/models/get_full_market_quote_response.c
    upstox_client/models/get_full_market_quote_response_v3.c
    upstox_client/models/get_gtt_order_response.c
    upstox_client/models/get_historical_candle_response.c
    upstox_client/models/get_holdings_response.c
    upstox_client/models/get_holiday_response.c
    upstox_client/models/get_intra_day_candle_response.c
    upstox_client/models/get_market_quote_last_traded_price_response.c
    upstox_client/models/get_market_quote_last_traded_price_response_v3.c
    upstox_client/models/get_market_quote_ohlc_response.c
    upstox_client/models/get_market_quote_ohlc_response_v3.c
    upstox_client/models/get_market_quote_option_greek_response_v3.c
    upstox_client/models/get_market_status_response.c
    upstox_client/models/get_mutual_fund_holdings_response.c
    upstox_client/models/get_mutual_fund_order_details_response.c
    upstox_client/models/get_mutual_fund_orders_response.c
    upstox_client/models/get_mutual_fund_sips_response.c
    upstox_client/models/get_news_response.c
    upstox_client/models/get_option_chain_response.c
    upstox_client/models/get_option_contract_response.c
    upstox_client/models/get_order_book_response.c
    upstox_client/models/get_order_details_response.c
    upstox_client/models/get_order_response.c
    upstox_client/models/get_position_response.c
    upstox_client/models/get_profile_response.c
    upstox_client/models/get_profit_and_loss_charges_response.c
    upstox_client/models/get_trade_response.c
    upstox_client/models/get_trade_wise_profit_and_loss_data_response.c
    upstox_client/models/get_trade_wise_profit_and_loss_meta_data_response.c
    upstox_client/models/get_us_exchange_timing_response.c
    upstox_client/models/get_us_holiday_response.c
    upstox_client/models/get_user_fund_margin_response.c
    upstox_client/models/get_user_fund_margin_v3_response.c
    upstox_client/models/gtt_cancel_order_request.c
    upstox_client/models/gtt_modify_order_request.c
    upstox_client/models/gtt_order_data.c
    upstox_client/models/gtt_order_details.c
    upstox_client/models/gtt_place_order_request.c
    upstox_client/models/gtt_rule.c
    upstox_client/models/gtt_trigger_order_response.c
    upstox_client/models/historical_candle_data.c
    upstox_client/models/history_item.c
    upstox_client/models/holdings_data.c
    upstox_client/models/holiday_data.c
    upstox_client/models/income_statement_data.c
    upstox_client/models/income_statement_entry.c
    upstox_client/models/income_statement_response.c
    upstox_client/models/indie_user_init_token_data.c
    upstox_client/models/indie_user_init_token_response.c
    upstox_client/models/indie_user_token_request.c
    upstox_client/models/initiate_payout_request.c
    upstox_client/models/instrument.c
    upstox_client/models/instrument_data.c
    upstox_client/models/intra_day_candle_data.c
    upstox_client/models/ipo_apply_data.c
    upstox_client/models/ipo_apply_request.c
    upstox_client/models/ipo_apply_response.c
    upstox_client/models/ipo_bid_request.c
    upstox_client/models/ipo_cancel_data.c
    upstox_client/models/ipo_cancel_response.c
    upstox_client/models/ipo_details_data.c
    upstox_client/models/ipo_details_response.c
    upstox_client/models/ipo_investor_type.c
    upstox_client/models/ipo_listing_data.c
    upstox_client/models/ipo_listing_response.c
    upstox_client/models/ipo_meta_data.c
    upstox_client/models/ipo_order_bid.c
    upstox_client/models/ipo_order_data.c
    upstox_client/models/ipo_order_detail_response.c
    upstox_client/models/ipo_order_response.c
    upstox_client/models/ipo_registrar_info.c
    upstox_client/models/ipo_timeline.c
    upstox_client/models/key_ratio_data.c
    upstox_client/models/key_ratios_response.c
    upstox_client/models/kill_switch_response.c
    upstox_client/models/kill_switch_segment_data.c
    upstox_client/models/kill_switch_segment_update_request.c
    upstox_client/models/logout_response.c
    upstox_client/models/loss.c
    upstox_client/models/margin.c
    upstox_client/models/margin_data.c
    upstox_client/models/margin_from_pledge.c
    upstox_client/models/margin_request.c
    upstox_client/models/market_data.c
    upstox_client/models/market_quote_ohlc.c
    upstox_client/models/market_quote_ohlcv3.c
    upstox_client/models/market_quote_option_greek_v3.c
    upstox_client/models/market_quote_symbol.c
    upstox_client/models/market_quote_symbol_ltp.c
    upstox_client/models/market_quote_symbol_ltp_v3.c
    upstox_client/models/market_quote_symbol_v3.c
    upstox_client/models/market_status_data.c
    upstox_client/models/modify_order_data.c
    upstox_client/models/modify_order_request.c
    upstox_client/models/modify_order_response.c
    upstox_client/models/modify_order_v3_response.c
    upstox_client/models/modify_payout_request.c
    upstox_client/models/multi_order_data.c
    upstox_client/models/multi_order_error.c
    upstox_client/models/multi_order_request.c
    upstox_client/models/multi_order_response.c
    upstox_client/models/multi_order_summary.c
    upstox_client/models/multi_order_v3_data.c
    upstox_client/models/mutual_fund_holding_data.c
    upstox_client/models/mutual_fund_meta_data.c
    upstox_client/models/mutual_fund_order_data.c
    upstox_client/models/mutual_fund_sip_data.c
    upstox_client/models/news_item_data.c
    upstox_client/models/news_response_meta_data.c
    upstox_client/models/news_response_page_data.c
    upstox_client/models/o_auth_client_exception.c
    upstox_client/models/o_auth_client_exception_cause.c
    upstox_client/models/o_auth_client_exception_cause_stack_trace_inner.c
    upstox_client/models/ohlc.c
    upstox_client/models/ohlc_v3.c
    upstox_client/models/option_strike_data.c
    upstox_client/models/order_book_data.c
    upstox_client/models/order_data.c
    upstox_client/models/order_metadata.c
    upstox_client/models/other_taxes.c
    upstox_client/models/pagination.c
    upstox_client/models/payment_history_data.c
    upstox_client/models/payment_history_response.c
    upstox_client/models/payout_details.c
    upstox_client/models/payout_details_response.c
    upstox_client/models/payout_modes_response.c
    upstox_client/models/place_order_data.c
    upstox_client/models/place_order_request.c
    upstox_client/models/place_order_response.c
    upstox_client/models/place_order_v3_request.c
    upstox_client/models/place_order_v3_response.c
    upstox_client/models/pledge_available_to_trade.c
    upstox_client/models/pledge_margin_used.c
    upstox_client/models/pledge_unavailable_to_trade.c
    upstox_client/models/position_data.c
    upstox_client/models/post_margin_response.c
    upstox_client/models/problem.c
    upstox_client/models/profile_data.c
    upstox_client/models/profit_and_loss_charges_data.c
    upstox_client/models/profit_and_loss_charges_taxes.c
    upstox_client/models/profit_and_loss_charges_wrapper_data.c
    upstox_client/models/profit_and_loss_meta_data.c
    upstox_client/models/profit_and_loss_meta_data_wrapper.c
    upstox_client/models/profit_and_loss_other_charges_taxes.c
    upstox_client/models/put_call_option_chain_data.c
    upstox_client/models/rule.c
    upstox_client/models/search_instrument_response.c
    upstox_client/models/search_meta_data.c
    upstox_client/models/sector_market_cap_amount.c
    upstox_client/models/share_holding_data.c
    upstox_client/models/share_holdings_response.c
    upstox_client/models/token_response.c
    upstox_client/models/totp_pin_token_request.c
    upstox_client/models/trade_data.c
    upstox_client/models/trade_history_response.c
    upstox_client/models/trade_history_response_meta_data.c
    upstox_client/models/trade_history_response_page_data.c
    upstox_client/models/trade_history_response_trade_data.c
    upstox_client/models/trade_wise_meta_data.c
    upstox_client/models/trade_wise_profit_and_loss_data.c
    upstox_client/models/unavailable_to_trade.c
    upstox_client/models/unsettled_profit.c
    upstox_client/models/update_user_ip_request.c
    upstox_client/models/us_exchange_timing_data.c
    upstox_client/models/us_funds_data.c
    upstox_client/models/us_funds_response.c
    upstox_client/models/us_holding_data.c
    upstox_client/models/us_holdings_response.c
    upstox_client/models/us_holiday_data.c
    upstox_client/models/us_margin_data.c
    upstox_client/models/us_margin_request.c
    upstox_client/models/us_margin_response.c
    upstox_client/models/us_order_book_data.c
    upstox_client/models/us_order_book_response.c
    upstox_client/models/us_order_data.c
    upstox_client/models/us_order_details_response.c
    upstox_client/models/us_order_estimate_data.c
    upstox_client/models/us_order_estimate_request.c
    upstox_client/models/us_order_estimate_response.c
    upstox_client/models/us_order_margin.c
    upstox_client/models/us_order_response.c
    upstox_client/models/us_place_order_request.c
    upstox_client/models/user_fund_margin_data.c
    upstox_client/models/user_fund_margin_v3_data.c
    upstox_client/models/user_ip_response.c
    upstox_client/models/user_ip_response_data.c
    upstox_client/models/websocket_auth_redirect_response.c
    upstox_client/models/websocket_auth_redirect_response_data.c
    upstox_client/api/ChargeAPI.c
    upstox_client/api/ExpiredInstrumentAPI.c
    upstox_client/api/FundamentalsAPI.c
    upstox_client/api/HistoryAPI.c
    upstox_client/api/HistoryV3API.c
    upstox_client/api/IPOAPI.c
    upstox_client/api/InstrumentsAPI.c
    upstox_client/api/LoginAPI.c
    upstox_client/api/MarketHolidaysAndTimingsAPI.c
    upstox_client/api/MarketQuoteAPI.c
    upstox_client/api/MarketQuoteV3API.c
    upstox_client/api/MutualFundAPI.c
    upstox_client/api/NewsAPI.c
    upstox_client/api/OptionsAPI.c
    upstox_client/api/OrderAPI.c
    upstox_client/api/OrderV3API.c
    upstox_client/api/PortfolioAPI.c
    upstox_client/api/PostTradeAPI.c
    upstox_client/api/TradeProfitAndLossAPI.c
    upstox_client/api/USMarketHolidaysAndTimingsAPI.c
    upstox_client/api/USStocksChargesAPI.c
    upstox_client/api/USStocksFundsAPI.c
    upstox_client/api/USStocksOrderAPI.c
    upstox_client/api/USStocksPortfolioAPI.c
    upstox_client/api/UserAPI.c
    upstox_client/api/WebsocketAPI.c

)

set(HDRS
    upstox_client/upstox.h
    upstox_client/include/apiClient.h
    upstox_client/include/list.h
    upstox_client/include/binary.h
    upstox_client/include/keyValuePair.h
    upstox_client/external/cJSON.h
    upstox_client/models/object.h
    upstox_client/models/any_type.h
    upstox_client/models/analytics_data.h
    upstox_client/models/analytics_response.h
    upstox_client/models/api_gateway_error_response.h
    upstox_client/models/available_to_trade.h
    upstox_client/models/balance_sheet_data.h
    upstox_client/models/balance_sheet_history_item.h
    upstox_client/models/balance_sheet_response.h
    upstox_client/models/batch_execution_summary.h
    upstox_client/models/brokerage_data.h
    upstox_client/models/brokerage_taxes.h
    upstox_client/models/brokerage_wrapper_data.h
    upstox_client/models/cancel_or_exit_multi_order_data.h
    upstox_client/models/cancel_or_exit_multi_order_response.h
    upstox_client/models/cancel_or_exit_order_error_data.h
    upstox_client/models/cancel_order_data.h
    upstox_client/models/cancel_order_response.h
    upstox_client/models/cancel_order_v3_response.h
    upstox_client/models/cas_eligible_status_data.h
    upstox_client/models/cash_available_to_trade.h
    upstox_client/models/cash_breakdown.h
    upstox_client/models/cash_flow_data.h
    upstox_client/models/cash_flow_entry.h
    upstox_client/models/cash_flow_response.h
    upstox_client/models/cash_margin_used.h
    upstox_client/models/cash_unavailable_to_trade.h
    upstox_client/models/company_profile_data.h
    upstox_client/models/company_profile_response.h
    upstox_client/models/competitor_data.h
    upstox_client/models/competitors_response.h
    upstox_client/models/convert_position_data.h
    upstox_client/models/convert_position_request.h
    upstox_client/models/convert_position_response.h
    upstox_client/models/corporate_action_data.h
    upstox_client/models/corporate_action_event_detail.h
    upstox_client/models/corporate_actions_response.h
    upstox_client/models/delivery_margin.h
    upstox_client/models/depth.h
    upstox_client/models/depth_map.h
    upstox_client/models/dp_plan.h
    upstox_client/models/exchange_timing_data.h
    upstox_client/models/expired_future_data.h
    upstox_client/models/family_member_data.h
    upstox_client/models/financial_statement_entry.h
    upstox_client/models/get_brokerage_response.h
    upstox_client/models/get_exchange_timing_response.h
    upstox_client/models/get_expired_futures_contract_response.h
    upstox_client/models/get_expiries_response.h
    upstox_client/models/get_full_market_quote_response.h
    upstox_client/models/get_full_market_quote_response_v3.h
    upstox_client/models/get_gtt_order_response.h
    upstox_client/models/get_historical_candle_response.h
    upstox_client/models/get_holdings_response.h
    upstox_client/models/get_holiday_response.h
    upstox_client/models/get_intra_day_candle_response.h
    upstox_client/models/get_market_quote_last_traded_price_response.h
    upstox_client/models/get_market_quote_last_traded_price_response_v3.h
    upstox_client/models/get_market_quote_ohlc_response.h
    upstox_client/models/get_market_quote_ohlc_response_v3.h
    upstox_client/models/get_market_quote_option_greek_response_v3.h
    upstox_client/models/get_market_status_response.h
    upstox_client/models/get_mutual_fund_holdings_response.h
    upstox_client/models/get_mutual_fund_order_details_response.h
    upstox_client/models/get_mutual_fund_orders_response.h
    upstox_client/models/get_mutual_fund_sips_response.h
    upstox_client/models/get_news_response.h
    upstox_client/models/get_option_chain_response.h
    upstox_client/models/get_option_contract_response.h
    upstox_client/models/get_order_book_response.h
    upstox_client/models/get_order_details_response.h
    upstox_client/models/get_order_response.h
    upstox_client/models/get_position_response.h
    upstox_client/models/get_profile_response.h
    upstox_client/models/get_profit_and_loss_charges_response.h
    upstox_client/models/get_trade_response.h
    upstox_client/models/get_trade_wise_profit_and_loss_data_response.h
    upstox_client/models/get_trade_wise_profit_and_loss_meta_data_response.h
    upstox_client/models/get_us_exchange_timing_response.h
    upstox_client/models/get_us_holiday_response.h
    upstox_client/models/get_user_fund_margin_response.h
    upstox_client/models/get_user_fund_margin_v3_response.h
    upstox_client/models/gtt_cancel_order_request.h
    upstox_client/models/gtt_modify_order_request.h
    upstox_client/models/gtt_order_data.h
    upstox_client/models/gtt_order_details.h
    upstox_client/models/gtt_place_order_request.h
    upstox_client/models/gtt_rule.h
    upstox_client/models/gtt_trigger_order_response.h
    upstox_client/models/historical_candle_data.h
    upstox_client/models/history_item.h
    upstox_client/models/holdings_data.h
    upstox_client/models/holiday_data.h
    upstox_client/models/income_statement_data.h
    upstox_client/models/income_statement_entry.h
    upstox_client/models/income_statement_response.h
    upstox_client/models/indie_user_init_token_data.h
    upstox_client/models/indie_user_init_token_response.h
    upstox_client/models/indie_user_token_request.h
    upstox_client/models/initiate_payout_request.h
    upstox_client/models/instrument.h
    upstox_client/models/instrument_data.h
    upstox_client/models/intra_day_candle_data.h
    upstox_client/models/ipo_apply_data.h
    upstox_client/models/ipo_apply_request.h
    upstox_client/models/ipo_apply_response.h
    upstox_client/models/ipo_bid_request.h
    upstox_client/models/ipo_cancel_data.h
    upstox_client/models/ipo_cancel_response.h
    upstox_client/models/ipo_details_data.h
    upstox_client/models/ipo_details_response.h
    upstox_client/models/ipo_investor_type.h
    upstox_client/models/ipo_listing_data.h
    upstox_client/models/ipo_listing_response.h
    upstox_client/models/ipo_meta_data.h
    upstox_client/models/ipo_order_bid.h
    upstox_client/models/ipo_order_data.h
    upstox_client/models/ipo_order_detail_response.h
    upstox_client/models/ipo_order_response.h
    upstox_client/models/ipo_registrar_info.h
    upstox_client/models/ipo_timeline.h
    upstox_client/models/key_ratio_data.h
    upstox_client/models/key_ratios_response.h
    upstox_client/models/kill_switch_response.h
    upstox_client/models/kill_switch_segment_data.h
    upstox_client/models/kill_switch_segment_update_request.h
    upstox_client/models/logout_response.h
    upstox_client/models/loss.h
    upstox_client/models/margin.h
    upstox_client/models/margin_data.h
    upstox_client/models/margin_from_pledge.h
    upstox_client/models/margin_request.h
    upstox_client/models/market_data.h
    upstox_client/models/market_quote_ohlc.h
    upstox_client/models/market_quote_ohlcv3.h
    upstox_client/models/market_quote_option_greek_v3.h
    upstox_client/models/market_quote_symbol.h
    upstox_client/models/market_quote_symbol_ltp.h
    upstox_client/models/market_quote_symbol_ltp_v3.h
    upstox_client/models/market_quote_symbol_v3.h
    upstox_client/models/market_status_data.h
    upstox_client/models/modify_order_data.h
    upstox_client/models/modify_order_request.h
    upstox_client/models/modify_order_response.h
    upstox_client/models/modify_order_v3_response.h
    upstox_client/models/modify_payout_request.h
    upstox_client/models/multi_order_data.h
    upstox_client/models/multi_order_error.h
    upstox_client/models/multi_order_request.h
    upstox_client/models/multi_order_response.h
    upstox_client/models/multi_order_summary.h
    upstox_client/models/multi_order_v3_data.h
    upstox_client/models/mutual_fund_holding_data.h
    upstox_client/models/mutual_fund_meta_data.h
    upstox_client/models/mutual_fund_order_data.h
    upstox_client/models/mutual_fund_sip_data.h
    upstox_client/models/news_item_data.h
    upstox_client/models/news_response_meta_data.h
    upstox_client/models/news_response_page_data.h
    upstox_client/models/o_auth_client_exception.h
    upstox_client/models/o_auth_client_exception_cause.h
    upstox_client/models/o_auth_client_exception_cause_stack_trace_inner.h
    upstox_client/models/ohlc.h
    upstox_client/models/ohlc_v3.h
    upstox_client/models/option_strike_data.h
    upstox_client/models/order_book_data.h
    upstox_client/models/order_data.h
    upstox_client/models/order_metadata.h
    upstox_client/models/other_taxes.h
    upstox_client/models/pagination.h
    upstox_client/models/payment_history_data.h
    upstox_client/models/payment_history_response.h
    upstox_client/models/payout_details.h
    upstox_client/models/payout_details_response.h
    upstox_client/models/payout_modes_response.h
    upstox_client/models/place_order_data.h
    upstox_client/models/place_order_request.h
    upstox_client/models/place_order_response.h
    upstox_client/models/place_order_v3_request.h
    upstox_client/models/place_order_v3_response.h
    upstox_client/models/pledge_available_to_trade.h
    upstox_client/models/pledge_margin_used.h
    upstox_client/models/pledge_unavailable_to_trade.h
    upstox_client/models/position_data.h
    upstox_client/models/post_margin_response.h
    upstox_client/models/problem.h
    upstox_client/models/profile_data.h
    upstox_client/models/profit_and_loss_charges_data.h
    upstox_client/models/profit_and_loss_charges_taxes.h
    upstox_client/models/profit_and_loss_charges_wrapper_data.h
    upstox_client/models/profit_and_loss_meta_data.h
    upstox_client/models/profit_and_loss_meta_data_wrapper.h
    upstox_client/models/profit_and_loss_other_charges_taxes.h
    upstox_client/models/put_call_option_chain_data.h
    upstox_client/models/rule.h
    upstox_client/models/search_instrument_response.h
    upstox_client/models/search_meta_data.h
    upstox_client/models/sector_market_cap_amount.h
    upstox_client/models/share_holding_data.h
    upstox_client/models/share_holdings_response.h
    upstox_client/models/token_response.h
    upstox_client/models/totp_pin_token_request.h
    upstox_client/models/trade_data.h
    upstox_client/models/trade_history_response.h
    upstox_client/models/trade_history_response_meta_data.h
    upstox_client/models/trade_history_response_page_data.h
    upstox_client/models/trade_history_response_trade_data.h
    upstox_client/models/trade_wise_meta_data.h
    upstox_client/models/trade_wise_profit_and_loss_data.h
    upstox_client/models/unavailable_to_trade.h
    upstox_client/models/unsettled_profit.h
    upstox_client/models/update_user_ip_request.h
    upstox_client/models/us_exchange_timing_data.h
    upstox_client/models/us_funds_data.h
    upstox_client/models/us_funds_response.h
    upstox_client/models/us_holding_data.h
    upstox_client/models/us_holdings_response.h
    upstox_client/models/us_holiday_data.h
    upstox_client/models/us_margin_data.h
    upstox_client/models/us_margin_request.h
    upstox_client/models/us_margin_response.h
    upstox_client/models/us_order_book_data.h
    upstox_client/models/us_order_book_response.h
    upstox_client/models/us_order_data.h
    upstox_client/models/us_order_details_response.h
    upstox_client/models/us_order_estimate_data.h
    upstox_client/models/us_order_estimate_request.h
    upstox_client/models/us_order_estimate_response.h
    upstox_client/models/us_order_margin.h
    upstox_client/models/us_order_response.h
    upstox_client/models/us_place_order_request.h
    upstox_client/models/user_fund_margin_data.h
    upstox_client/models/user_fund_margin_v3_data.h
    upstox_client/models/user_ip_response.h
    upstox_client/models/user_ip_response_data.h
    upstox_client/models/websocket_auth_redirect_response.h
    upstox_client/models/websocket_auth_redirect_response_data.h
    upstox_client/api/ChargeAPI.h
    upstox_client/api/ExpiredInstrumentAPI.h
    upstox_client/api/FundamentalsAPI.h
    upstox_client/api/HistoryAPI.h
    upstox_client/api/HistoryV3API.h
    upstox_client/api/IPOAPI.h
    upstox_client/api/InstrumentsAPI.h
    upstox_client/api/LoginAPI.h
    upstox_client/api/MarketHolidaysAndTimingsAPI.h
    upstox_client/api/MarketQuoteAPI.h
    upstox_client/api/MarketQuoteV3API.h
    upstox_client/api/MutualFundAPI.h
    upstox_client/api/NewsAPI.h
    upstox_client/api/OptionsAPI.h
    upstox_client/api/OrderAPI.h
    upstox_client/api/OrderV3API.h
    upstox_client/api/PortfolioAPI.h
    upstox_client/api/PostTradeAPI.h
    upstox_client/api/TradeProfitAndLossAPI.h
    upstox_client/api/USMarketHolidaysAndTimingsAPI.h
    upstox_client/api/USStocksChargesAPI.h
    upstox_client/api/USStocksFundsAPI.h
    upstox_client/api/USStocksOrderAPI.h
    upstox_client/api/USStocksPortfolioAPI.h
    upstox_client/api/UserAPI.h
    upstox_client/api/WebsocketAPI.h

)

include(PreTarget.cmake OPTIONAL)

set(PROJECT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Add library with project file with project name as library name
if(NOT BUILD_STATIC_LIBS)
  add_library(${pkgName} ${SRCS} ${HDRS})
else()
  add_library(${pkgName} STATIC ${SRCS} ${HDRS})
endif()
# Link dependent libraries
if(NOT CMAKE_VERSION VERSION_LESS 3.4)
    target_link_libraries(${pkgName} PRIVATE OpenSSL::SSL OpenSSL::Crypto)
endif()
target_link_libraries(${pkgName} PUBLIC ${CURL_LIBRARIES} )
target_include_directories(
    ${pkgName} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

include(PostTarget.cmake OPTIONAL)

# installation of libraries, headers, and config files
if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in)
    install(TARGETS ${pkgName} DESTINATION lib)
else()
    include(GNUInstallDirs)
    install(TARGETS ${pkgName} DESTINATION lib EXPORT ${pkgName}Targets)

    foreach(HDR_FILE ${HDRS})
        get_filename_component(HDR_DIRECTORY ${HDR_FILE} DIRECTORY)
        get_filename_component(ABSOLUTE_HDR_DIRECTORY ${HDR_DIRECTORY} ABSOLUTE)
        file(RELATIVE_PATH RELATIVE_HDR_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${ABSOLUTE_HDR_DIRECTORY})
        install(FILES ${HDR_FILE} DESTINATION include/${RELATIVE_HDR_PATH})
    endforeach()

    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            VERSION "${PROJECT_VERSION_STRING}"
            COMPATIBILITY AnyNewerVersion
    )

    export(EXPORT ${pkgName}Targets
            FILE "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Targets.cmake"
            NAMESPACE ${pkgName}::
            )

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            @ONLY
            )

    set(ConfigPackageLocation lib/cmake/${pkgName})
    install(EXPORT ${pkgName}Targets
            FILE
            ${pkgName}Targets.cmake
            NAMESPACE
            ${pkgName}::
            DESTINATION
            ${ConfigPackageLocation}
            )
    install(
            FILES
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            DESTINATION
            ${ConfigPackageLocation}
    )
endif()

# make installation packages
include(Packing.cmake OPTIONAL)

# Setting file variables to null
set(SRCS "")
set(HDRS "")


## This section shows how to use the above compiled library to compile the source files
## set source files
#set(SRCS
#    unit-tests/manual-ChargeAPI.c
#    unit-tests/manual-ExpiredInstrumentAPI.c
#    unit-tests/manual-FundamentalsAPI.c
#    unit-tests/manual-HistoryAPI.c
#    unit-tests/manual-HistoryV3API.c
#    unit-tests/manual-IPOAPI.c
#    unit-tests/manual-InstrumentsAPI.c
#    unit-tests/manual-LoginAPI.c
#    unit-tests/manual-MarketHolidaysAndTimingsAPI.c
#    unit-tests/manual-MarketQuoteAPI.c
#    unit-tests/manual-MarketQuoteV3API.c
#    unit-tests/manual-MutualFundAPI.c
#    unit-tests/manual-NewsAPI.c
#    unit-tests/manual-OptionsAPI.c
#    unit-tests/manual-OrderAPI.c
#    unit-tests/manual-OrderV3API.c
#    unit-tests/manual-PortfolioAPI.c
#    unit-tests/manual-PostTradeAPI.c
#    unit-tests/manual-TradeProfitAndLossAPI.c
#    unit-tests/manual-USMarketHolidaysAndTimingsAPI.c
#    unit-tests/manual-USStocksChargesAPI.c
#    unit-tests/manual-USStocksFundsAPI.c
#    unit-tests/manual-USStocksOrderAPI.c
#    unit-tests/manual-USStocksPortfolioAPI.c
#    unit-tests/manual-UserAPI.c
#    unit-tests/manual-WebsocketAPI.c
#)

##set header files
#set(HDRS
#)

## loop over all files in SRCS variable
#foreach(SOURCE_FILE ${SRCS})
#    # Get only the file name from the file as add_executable does not support executable with slash("/")
#    get_filename_component(FILE_NAME_ONLY ${SOURCE_FILE} NAME_WE)
#    # Remove .c from the file name and set it as executable name
#    string( REPLACE ".c" "" EXECUTABLE_FILE ${FILE_NAME_ONLY})
#    # Add executable for every source file in  SRCS
#    add_executable(unit-${EXECUTABLE_FILE} ${SOURCE_FILE})
#    # Link above created library to executable and dependent library curl
#    target_link_libraries(unit-${EXECUTABLE_FILE} ${CURL_LIBRARIES} ${pkgName} )
#endforeach(SOURCE_FILE ${SRCS})
