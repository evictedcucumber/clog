# clog

A custom logger written in C.

## Usage

### Debug Logging

Do either of the following to enable debug logging:

> Compile with `-DCLOG_ENABLE_DEBUG`

OR

```c
#define CLOG_ENABLE_DEBUG
#include "clog.h"
```

### Prefixes

Prefixes are automatically removed by default, however should you require them to prevent collisions with other modules you can do either of the following:

> Compile with `-DCLOG_ENABLE_PREFIX`

OR

```c
#define CLOG_ENABLE_PREFIX
#include "clog.h"
```

### Colours

Do either of the following to enable colours:

> Compile with `-DCLOG_ENABLE_COLOURS`

OR

```c
#define CLOG_ENABLE_COLOURS
#include "clog.h"
```

### Timestamps

Do either of the following to enable timestamps:

> Compile with `-DCLOG_ENABLE_TIMESTAMPS`

OR

```c
#define CLOG_ENABLE_TIMESTAMPS
#include "clog.h"
```

## Testing

Testing the library is as simple as running the following:

```bash
chmod +x ./run_tests.sh
./run_tests.sh
```
