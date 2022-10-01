
class Car
    def initialize(p1,p2)
    @a = p1
    @b = p2
    end

    def print_me
        puts @a 
        puts @b    
    end
end


car1 = Car.new("a", "b")
car1.instance_variable_set(:@a, "Dodge")
car1.instance_variable_set("@b", "Audi")

car1.inspect 

puts car1.print_me