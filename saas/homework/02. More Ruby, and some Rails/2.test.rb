=begin
class RandomSequence
  def initialize(limit,num)
    @limit,@num = limit,num
  end
  def each
    @num.times { yield (rand * @limit).floor }
  end
end

#n = RandomSequence.new(10,4)
#p n

i = -1
RandomSequence.new(10,4).each do |num|
  i = num if i < num
  p i
end
=end

class CartesianProduct
  include Enumerable
  # your code here
  def initialize( a, b )
    @a = a
    @b = b
  end
  def each
	@a.each { |a| @b.each { |b| yield [a, b] } }
  end
end

c = CartesianProduct.new([:a,:b], [4,5])
c.each { |elt| puts elt.inspect }
# [:a, 4]
# [:a, 5]
# [:b, 4]
# [:b, 5]

c = CartesianProduct.new([:a,:b], [])
c.each { |elt| puts elt.inspect }
# (nothing printed since Cartesian product
# of anything with an empty collection is empty)

c = CartesianProduct.new([:a,:b,nil], ['qw', '23', 999, :sss])
c.each { |elt| puts elt.inspect }
