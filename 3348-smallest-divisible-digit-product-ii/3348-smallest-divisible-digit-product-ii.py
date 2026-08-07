class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        c2 = c3 = c5 = c7 = 0
        while t % 2 == 0:
            c2 += 1
            t //= 2
        while t % 3 == 0:
            c3 += 1
            t //= 3
        while t % 5 == 0:
            c5 += 1
            t //= 5
        while t % 7 == 0:
            c7 += 1
            t //= 7

        if t > 1:
            return "-1"

        def min_digits(r2, r3, r5, r7):
            r2 = max(0, r2)
            r3 = max(0, r3)
            r5 = max(0, r5)
            r7 = max(0, r7)

            def calc(count2, count3):
                d3 = (count3 + 1) // 2
                d2 = (count2 + 2) // 3
                return d3 + d2

            opt1 = calc(r2, r3)
            opt2 = 1 + calc(max(0, r2 - 1), max(0, r3 - 1))
            return r5 + r7 + min(opt1, opt2)

        def consume(d, r2, r3, r5, r7):
            if d == 2: r2 -= 1
            elif d == 3: r3 -= 1
            elif d == 4: r2 -= 2
            elif d == 5: r5 -= 1
            elif d == 6: r2 -= 1; r3 -= 1
            elif d == 7: r7 -= 1
            elif d == 8: r2 -= 3
            elif d == 9: r3 -= 2
            return r2, r3, r5, r7

        n = len(num)
        first_zero = n
        for i in range(n):
            if num[i] == '0':
                first_zero = i
                break

        p2, p3, p5, p7 = [0] * (n + 1), [0] * (n + 1), [0] * (n + 1), [0] * (n + 1)
        for i in range(first_zero):
            p2[i + 1], p3[i + 1], p5[i + 1], p7[i + 1] = consume(
                int(num[i]), p2[i], p3[i], p5[i], p7[i]
            )

        if first_zero == n and min_digits(c2 + p2[n], c3 + p3[n], c5 + p5[n], c7 + p7[n]) <= 0:
            return num

        for i in range(min(n - 1, first_zero), -1, -1):
            req2 = c2 + p2[i]
            req3 = c3 + p3[i]
            req5 = c5 + p5[i]
            req7 = c7 + p7[i]

            start_d = int(num[i]) + 1 if i < first_zero else 1

            for d in range(start_d, 10):
                cur2, cur3, cur5, cur7 = consume(d, req2, req3, req5, req7)
                rem_len = n - 1 - i
                if min_digits(cur2, cur3, cur5, cur7) <= rem_len:
                    res = list(num[:i]) + [str(d)]
                    for j in range(i + 1, n):
                        for next_d in range(1, 10):
                            nxt2, nxt3, nxt5, nxt7 = consume(next_d, cur2, cur3, cur5, cur7)
                            if min_digits(nxt2, nxt3, nxt5, nxt7) <= n - 1 - j:
                                res.append(str(next_d))
                                cur2, cur3, cur5, cur7 = nxt2, nxt3, nxt5, nxt7
                                break
                    return "".join(res)

        target_len = max(n + 1, min_digits(c2, c3, c5, c7))
        res = []
        cur2, cur3, cur5, cur7 = c2, c3, c5, c7

        for j in range(target_len):
            for d in range(1, 10):
                nxt2, nxt3, nxt5, nxt7 = consume(d, cur2, cur3, cur5, cur7)
                if min_digits(nxt2, nxt3, nxt5, nxt7) <= target_len - 1 - j:
                    res.append(str(d))
                    cur2, cur3, cur5, cur7 = nxt2, nxt3, nxt5, nxt7
                    break

        return "".join(res)