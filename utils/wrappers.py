from functools import wraps


def time_execution(func):
    from timeit import default_timer as timer

    @wraps(func)
    def wrapper(self, *args, **kwargs):
        start = timer()
        res = func(self, *args, **kwargs)
        stop = timer()
        self.execution_time = stop - start
        return res

    return wrapper
