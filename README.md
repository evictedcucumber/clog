# clog

A custom logger written in C.

## Debug Logging

Do either of the following to enable debug logging:

> Add `-DCLOG_ENABLE_DEBUG` to your build step

OR

```c
#define CLOG_ENABLE_DEBUG
#include "clog.h"
```

## Prefixes

Prefixes are automatically removed by default, however should you require them to prevent collisions with other modules you can do either of the following:

> Add `-DCLOG_ENABLE_PREFIX` to your build step

OR

```c
#define CLOG_ENABLE_PREFIX
#include "clog.h"
```

## Testing

Testing the library is as simple as running the following:

```bash
chmod +x ./run_tests.sh
./run_tests.sh
```
