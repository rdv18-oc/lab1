FROM ubuntu:22.04

RUN apt-get update && apt-get install -y build-essential \
    && rm -rf /var/lib/apt/lists/*

COPY text-processor-v17.deb /tmp/text-processor.deb

RUN dpkg -i /tmp/text-processor.deb || apt-get install -f -y

CMD ["/usr/bin/text_processor"] # test trigger 3