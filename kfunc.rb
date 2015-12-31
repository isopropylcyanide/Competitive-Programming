
=begin
f a sequence of numbers a1, A2, ... , AN form an arithmetic progression A, he was asked to calculate sum of F(Ai),
for L <= i <= R. F(X) is defined as: If X < 10 then F(X) = X. Else F(X) = F(sum_of_digits(X)).	
=end

TAB = [[]] * 10
TSUM = 45

TAB[1] = [1, 2, 3, 4, 5, 6, 7, 8, 9]
TAB[2] = [2, 4, 6, 8, 1, 3, 5, 7, 9]
TAB[3] = [3, 6, 9, 3, 6, 9, 3, 6, 9]
TAB[4] = [4, 8, 3, 7, 2, 6, 1, 5, 9]
TAB[5] = [5, 1, 6, 2, 7, 3, 8, 4, 9]
TAB[6] = [6, 3, 9, 6, 3, 9, 6, 3, 9]
TAB[7] = [7, 5, 3, 1, 8, 6, 4, 2, 9]
TAB[8] = [8, 7, 6, 5, 4, 3, 2, 1, 9]
TAB[9] = [9, 9, 9, 9, 9, 9, 9, 9, 9]


t = gets.chomp.to_i

t.times do
	a1,d,l,r = gets.split(&:to_i)
	a1,d,l,r=a1.to_i,d.to_i,l.to_i,r.to_i

	n = r - l + 1
    d = d % 9
    a1 = a1 + d * (l - 1)

    if d == 0
    	puts (1 + (a1 - 1) % 9)* n

	elsif d==3
		first = 1 + (a1 - 1) % 9
        second = 1 + (first + 3 - 1) % 9
        third = 1 + (second + 3 - 1) % 9

        ans = 0
        quo, mod = n.divmod(3)

        ans += quo * (first + second + third)
        if mod == 1
            ans += first
        elsif mod == 2
            ans += first + second
        end
        puts ans

    elsif d==6
    	first = 1 + (a1 - 1) % 9
        second = 1 + (first + 6 - 1) % 9
        third = 1 + (second + 6 - 1) % 9

        ans = 0
        quo, mod = n.divmod(3)

        ans += quo * (first + second + third)
        if mod == 1
            ans += first
        elif mod == 2
            ans += first + second
        end
        puts ans
    
    else
            first_in_table = 1 + (a1 - 1) % 9

            first_in_table_index = TAB[d].index(first_in_table)

            if n <= 9 - first_in_table_index
                puts TAB[d][first_in_table_index, n].inject(:+)

            else
                ans = 0
                offset = 9 - first_in_table_index
                ans += (TAB[d][first_in_table_index,TAB[d].length]).inject(:+)

                n -= offset
                mult, mod = n.divmod(9)

                ans += TSUM * mult
                ans += (TAB[d][0,mod]).inject(:+)

                puts ans
            end	

	end
end
