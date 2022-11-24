Beat Clock
==========

[Back in 2015][post] I wanted to build an clock based off segmented LED displays that showed the time in [Swatch Internet Time (.beats)][sit] format -- the official time format of [tilde.town][tt].

A mere 7 years later, this is that clock.

It's written in pure C with no external libraries and only targets Raspberry Pi's running Linux, with the kernel-level I<sup>2</sup>C stack.

![LED Clock](https://github.com/insom/beatclock/blob/main/clock.jpg?raw=true)

- Obtain a Raspberry Pi
- And an [Adafruit 14-segment LED display (with I<sup>2</sup>C Backpack)][ada]
- Wire them [like Adafruit suggests](https://learn.adafruit.com/adafruit-led-backpack/0-54-alphanumeric-python-wiring-and-setup#wiring-original-version-3128023)
- Add `dtparam=i2c_arm=on` to `/boot/config.txt`
- `make && ./beatclock`

Enjoy.

(Thank you to Dave Madison who [documented the protocol in an approachable way][doc].)

[post]: https://github.com/insom/website/blob/master/_posts/2015/2015-12-09-beat-clock.md
[tt]: https://tilde.town/
[sit]: https://en.wikipedia.org/wiki/Swatch_Internet_Time
[doc]: https://www.partsnotincluded.com/controlling-led-matrix-with-the-ht16k33/
[ada]: https://www.adafruit.com/product/2158

License
-------

Copyright (c) 2022, Aaron Brady

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
