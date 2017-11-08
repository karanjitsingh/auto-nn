import numpy as np


class Exponential:
	def __init__(self, start, stop):
		self.start = start
		self.stop = stop

	def __call__(self, step):
		value = np.exp(np.log(self.stop) * step)
		return self.start * np.exp(np.log(self.stop) * step)


class Linear:
	def __init__(self, start, stop):
		self.start = start
		self.stop = stop

	def __call__(self, step):
		return self.start - (self.start - self.stop) * step


class Const:
	def __init__(self, val):
		self.val = val

	def __call__(self, unused):
		return self.val
