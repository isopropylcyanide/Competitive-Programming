
# Chef arranges the N robots in a row, in the (increasing) order of their indices. Then, he chooses the first M robots and
#  moves them to the end of the queue. Now, Chef goes to the robot at the first position in the row and hands it one cake.
#  He then notes this robot's index (say k) in his notebook, and goes to the kth position in the row. If the robot at this
#  position does not have a cake, he give him one cake, notes his index in his notebook, and continues the same process.
#  If a robot visited by Chef already has a cake with it, then he stops moving and the cake assignment process is stopped.

def solve(n, m)
    if n == 1 || m == n - 1 || m == 1
        puts 'Yes'
    elsif m == 0
        puts 'No 1'
    else
        m = [m, n - m].min

        if n % m == 0
            puts 'No %d' % [n / m]
        else
            ans = n.gcd(m)
            if ans == 1
                puts 'Yes'
            else
                puts 'No %d' % [n / ans]
            end
        end

    end
end
t = gets.chomp.to_i

t.times do
    n, m = gets.split.map(&:to_i)
    solve(n, m)
end
