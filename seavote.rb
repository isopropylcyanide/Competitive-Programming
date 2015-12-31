#if there exists some statistics A which could be rounded to make it 100, print YES otherwise NO. 
 
 def checker(n,arr)
      
      Integer count=0,sum=0
      arr.each {|i| sum+=i }
      arr.each {|i| count+=1 if i==0}
 
      if sum==100
      	puts "YES"
      	return
      	 
      elsif sum<100
      	puts "NO"
      	return
     
      elsif sum<(100+arr.length-count)
        puts "YES"
      	return
      
      elsif (sum>=100+arr.length-count)
        puts "NO"
        return
        
      else
        puts "YES"
        return
      end
 end
 
 t=gets.chomp.to_i
 
 while t!=0
      n=gets.chomp
  
      arr=gets.split.map(&:to_i)

      checker(n,arr)
      t-=1
  
 end
