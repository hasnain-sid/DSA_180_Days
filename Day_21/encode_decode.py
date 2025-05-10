class Codec:
    def encode(self, strs: List[str]) -> str:
        encoded = ''
        for s in strs:
            encoded += f"{len(s)}#{s}"
        return encoded

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while i < len(s):
            # find where the '#' is to extract the length
            j = i
            while s[j] != '#':
                j += 1
            length = int(s[i:j])
            word = s[j+1:j+1+length]
            res.append(word)
            i = j + 1 + length
        return res
