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
