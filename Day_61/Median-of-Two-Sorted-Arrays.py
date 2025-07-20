class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1)>len(nums2):           #Need to do bs on shorter one to prevent out of bounds on other one
            nums1,nums2=nums2,nums1
        
        n1,n2=len(nums1),len(nums2)
        low,high=0,n1
        half=(n1+n2+1)//2       #Why +1??

        while(low<=high):           #Why <=? cuz finding exact target val??
            mid1=(low+high)//2          #partition cuts
            mid2=half-mid1

            l1=nums1[mid1-1] if mid1>=1 else float('-inf') # Left and right values around the cuts
            l2=nums2[mid2-1] if mid2>=1 else float('-inf')      
            r1=nums1[mid1] if mid1<n1 else float('inf')    #since it has to be in increasing order
            r2=nums2[mid2] if mid2<n2 else float('inf')

            if l1<=r2 and l2<=r1:           #Valid order, so find median
                if (n1+n2)%2==0:            #Even, so median is sum of middle elements
                    return (max(l1,l2)+min(r1,r2))/2
                else:
                    return max(l1,l2)       #Since left has an extra element
            elif l1>r2:         #Move left to remove the bigger element from consideration
                high=mid1-1
            else:                   #Condition: l2>r1, move right to include smaller element
                low=mid1+1


