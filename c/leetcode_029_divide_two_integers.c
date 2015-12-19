int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    int minus = (dividend ^ divisor) < 0;
    if (dividend > 0) dividend = -dividend;
    if (divisor  > 0) divisor  = -divisor;

    int to = 0;
    while ((divisor << 1) < 0 && (divisor << 1) >= dividend)
    {
        divisor <<= 1;
        to++;
    }

    int out = 0;
    for (int i = to; i >= 0; i--)
    {
        if (dividend <= divisor)
        {
            dividend -= divisor;
            out += 1 << i;
            if (!dividend) break;
        }
        divisor >>= 1;
    }
    return minus ? -out : out;
}
