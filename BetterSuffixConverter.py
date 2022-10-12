from __future__ import annotations

def _converter(stat) ->  int | None:
    suffix_converter = {
        "k": 1_000,
        "m": 1_000_000,
        "b": 1_000_000_000,
        "t": 1_000_000_000_000,
        "qa": 1_000_000_000_000_000
    }
    if re.search("[a-zA-Z]+", stat):
        digit = float((re.sub("[a-zA-Z]+", "", stat)))
        letter = (re.sub("[^a-zA-Z]", "", stat)).lower()
        return (
            float(digit * (suffix_converter.get(letter)))
            if suffix_converter.get(letter) is not None
            else None
        )
    return stat