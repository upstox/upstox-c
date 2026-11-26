# Portfolio Stream Feed WebSocket Client

This C program demonstrates how to connect to the Upstox WebSocket API for streaming live order updates. It receives the order updates and prints them to the console.

## Getting Started

These instructions will help you build and run the sample websocket client.

### Prerequisites

You need CMake 3.x, a C compiler, [protobuf-c](https://github.com/protobuf-c/protobuf-c) (the feeder library needs it) and a libcurl built with WebSocket support (7.86 or later). On macOS:

```sh
brew install cmake curl protobuf-c
```

### Configuration

The program reads your Upstox API access token from the `UPSTOX_ACCESS_TOKEN` environment variable.

### Running the Program

Build the examples from the repository root, then run the program:

```sh
cmake -S . -B build -DCMAKE_PREFIX_PATH=$(brew --prefix curl) -DUPSTOX_BUILD_EXAMPLES=ON
cmake --build build
UPSTOX_ACCESS_TOKEN=... ./build/example_websocket_order_updates_main
```

Press Ctrl+C to stop streaming.

## Understanding the Code

The program creates an API client with your access token and a `portfolio_data_streamer_t` with order updates enabled. On connect, the streamer authorizes with the access token and opens the WebSocket connection.

Each order update arrives as a JSON message, which the program prints to the console. Pass 1 for the position, holding or GTT flags of `portfolio_data_streamer_create` to receive those updates as well.

## Support

If you encounter any problems or have any questions about this project, feel free to post it on our [Developer Community](https://community.upstox.com/c/developer-api/15).

## Disclaimer

This is a sample program meant for educational purposes. It may require modifications to work with your specific requirements.
