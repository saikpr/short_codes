#!/usr/bin/python
# -*- coding: utf-8 -*-

import random as rnd
import numpy as np
from PIL import Image
from itertools import cycle


def main():
    # Input paramentri di lcg
    m = int(input("m: "))
    a = int(input("a: "))
    c = int(input("c: "))
    seed = rnd.randint(0, m - 1)

    # Genera e visualizza la sequence di m-1 valori
    sequence = generate_sequence(m, a, c, seed, count=m, full=False, check=False)
    print("SEed: " + str(seed))
    print(sequence)

    # Visualizzazione pattern mediante un'immagine
    old_min = min(sequence)
    old_max = max(sequence)
    new_min = 0
    new_max = 255

    # Normalizzazione dei valori [0 - 255]
    values = [((x - old_min) * (new_max - new_min) / (old_max - old_min)) + new_min for x in sequence]

    row = cycle(values)
    arr_img = np.array([[row.next() for i in range(0, 301)]] * 300)
    img = Image.fromarray(arr_img)
    img.show("Generatore lineare congruenziale")


def generate_sequence(m, a, c, seed, count, full=True, check=True):
    seq = []
    xn = seed

    if check:
        if m < 0 or a >= m or a <= 0 or c >= m or c < 0:
            return None

    if full:
        if mcd(c, m) != 1 or not divisibile_fattori_primi(a-1, m) or not ((a - 1) % 4 == 0 and m % 4 == 0):
            return None

    generatore = lcg(m, a, c, seed)

    for i in range(count):
        seq.append(generatore.next())

    return seq


def lcg(m, a, c, seed):
    _xn = seed

    while True:
        yield _xn
        _xn = (a * _xn + c) % m  # Et voilà!


def mcd(a, b):
    while b != 0:
        resto = a % b
        a = b
        b = resto

    return a


def fattori_primi(n):
    fatt = []
    d = 2

    while d*d <= n:
        while n % d == 0:
            fatt.append(d)
            n /= d
        d += 1

    if n > 1:
        fatt.append(n)

    return fatt


def divisibile_fattori_primi(a, b):
    fatt_primi = fattori_primi(b)

    for i in fatt_primi:
        if a % i != 0:
            return False

    return True


if __name__ == "__main__":
    main()