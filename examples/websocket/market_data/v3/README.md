# Market Stream feed websocket client

This C program demonstrates how to connect to the Upstox WebSocket API for streaming live market data. It subscribes to a list of instrument keys and prints the last traded price from each decoded protobuf update.

## Getting Started

These instructions will help you build and run the sample v3 websocket client.

### Prerequisites

You need CMake 3.x, a C compiler, [protobuf-c](https://github.com/protobuf-c/protobuf-c) and a libcurl built with WebSocket support (7.86 or later). On macOS:

```sh
brew install cmake curl protobuf-c
```

### Protocol Buffers (Protobuf) Classes

The SDK ships the generated protobuf-c types for the v3 feed in `upstox_client/feeder/marketdatav3/`, so you do not need to run `protoc` yourself.

To regenerate them from the [proto file](https://assets.upstox.com/feed/market-data-feed/v3/MarketDataFeed.proto), install `protoc` and the `protoc-gen-c` plugin (part of protobuf-c), then run:

```sh
cd upstox_client/feeder/marketdatav3
protoc --c_out=. MarketDataFeedV3.proto
```

### Configuration

The program reads your Upstox API access token from the `UPSTOX_ACCESS_TOKEN` environment variable.

### Running the Program

Build the examples from the repository root, then run the program:

```sh
cmake -S . -B build -DCMAKE_PREFIX_PATH=$(brew --prefix curl) -DUPSTOX_BUILD_EXAMPLES=ON
cmake --build build
UPSTOX_ACCESS_TOKEN=... ./build/example_websocket_market_data_v3_main
```

Press Ctrl+C to stop streaming.

## Understanding the Code

The program creates an API client with your access token and a `market_data_streamer_v3_t` for "NSE_INDEX|Nifty Bank" and "NSE_INDEX|Nifty 50" in `full` mode. On connect, the streamer authorizes with the access token, opens the WebSocket and sends the subscription request.

Each message from the server is decoded into a `upstox_feed_response_t`; the program finds the LTPC block of each feed (whatever the mode) and prints it. If the connection drops, the streamer reconnects (every 5 seconds, up to 10 times) and subscribes again.

## Support

If you encounter any problems or have any questions about this project, feel free to post it on our [Developer Community](https://community.upstox.com/c/developer-api/15).

## Disclaimer

This is a sample program meant for educational purposes. It may require modifications to work with your specific requirements.
