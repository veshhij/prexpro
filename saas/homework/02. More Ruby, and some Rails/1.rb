class Numeric
  @@currencies = {'yen' => 0.013, 'euro' => 1.292, 'rupee' => 0.019, 'dollar' => 1.0 }

  def method_missing(method_id)
    singular_currency = method_id.to_s.gsub( /s$/, '')
    if @@currencies.has_key?(singular_currency)
      self * @@currencies[singular_currency]
    else
      super
    end
  end
  def in( in_currency )
    singular_currency = in_currency.to_s.gsub( /s$/, '')
    if @@currencies.has_key?(singular_currency)
	  self * 1.0 / @@currencies[singular_currency]
    else
      super
    end
  end
end

class String
  def palindrome?
    s = self.downcase.gsub( /\W/, ' ' ).split( ' ' ).join
	s == s.reverse
  end
end

module Enumerable
  def palindrome?
    a = collect { |i| i }
	a == a.reverse
  end
end
