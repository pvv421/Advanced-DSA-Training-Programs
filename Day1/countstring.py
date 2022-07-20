def countString(s):
    ans = ''
    temp = s[0]
    count = 1
    for i in range(1,len(s)):
        if temp == s[i]:
            count+=1
        else:
            ans = ans+str(count)+temp
            temp = s[i]
            count = 1
    ans = ans+str(count)+temp
    return ans
print(countString("wwweerrtttte"))