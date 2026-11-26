# Live sanity programs

`sanity.c` and `sandbox_sanity.c` port the Python SDK's `test/sdk_tests/sanity.py` and `sandbox_sanity.py`. They call the real Upstox API through the C SDK. Each one makes the same calls in the same order as the Python script, with the same checks:

- A call fails when it returns `NULL`, when its `status` is not `success`, or when its `data` is `NULL`.
- An expected-error probe fails when the error code is not in Python's list. The code is read from `errors[0].errorCode` or `errors[0].error_code` in `apiClient->errorBody`.

On a failure, the program prints Python's message, plus the HTTP status and error body. At the end it prints `N checks, M failed` and exits with status 1 if any check failed. With no token, it prints how to set one and exits with status 1.

## Tokens

Both programs read credentials and sample data from `data_token.h`, the counterpart of Python's `data_token.py`:

- `DATA_TOKEN_ACCESS_TOKEN`: the live token. `UPSTOX_ACCESS_TOKEN` overrides it.
- `DATA_TOKEN_SANDBOX_ACCESS_TOKEN`: the sandbox token. `UPSTOX_SANDBOX_ACCESS_TOKEN` overrides it.
- `DATA_TOKEN_ALGO_NAME` and `DATA_TOKEN_SAMPLE_INSTRUMENT_KEY`: sample data for order and quote calls.

The environment variables win when they are set. **Never commit a filled-in `data_token.h`.** To stop git from picking up your local edits, run:

```bash
git update-index --skip-worktree test/sdk_tests/data_token.h
```

## Building and running

```bash
cmake -S . -B build -DCMAKE_PREFIX_PATH=$(brew --prefix curl) && cmake --build build
./build/sanity           # live API, uses DATA_TOKEN_ACCESS_TOKEN / UPSTOX_ACCESS_TOKEN
./build/sandbox_sanity   # sandbox, uses DATA_TOKEN_SANDBOX_ACCESS_TOKEN / UPSTOX_SANDBOX_ACCESS_TOKEN
```

## Account-changing calls

Like the Python script, `sanity` runs every call with no gates, including the ones that change the account. Read the list before running it against a real account:

- places v2, v3, multi and GTT orders (LIMIT/AMO, small quantities) in the main and the algo-name blocks, and cancels multi orders by tag
- exits positions by tag and converts a position
- sets the static IP to `1.2.3.4` and disables the NSE_EQ kill-switch segment
- logs out at the end, which invalidates the token

IPO apply/cancel and payout initiate/modify/cancel stay off, as in Python (`RUN_DESTRUCTIVE_IPO_TESTS` / `RUN_DESTRUCTIVE_PAYOUT_TESTS` in `sanity.c`). `sandbox_sanity` sends orders to the sandbox only.
